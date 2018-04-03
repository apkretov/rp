#include <pthread.h>
#include <time.h>
#include "errors.h"

typedef struct alarm_tag { //The "alarm" structure now contains the time_t for each alarm, so that they can be sorted. Storing the requested number of seconds would not be enough, since the "alarm thread" cannot tell how long it has been on the list.
	struct alarm_tag* link;
	int seconds;
	time_t time; //seconds from EPOCH
	char message[64];
} alarm_t;

pthread_mutex_t msttAlarm_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t msttAlarm_cond = PTHREAD_COND_INITIALIZER; //20,22: Part 1 shows the declarations for alarm_cond.c. There are two additions to this section, compared to alarm_mutex.c: a condition variable called alarm_cond...
alarm_t* msttAlarm_list = NULL;
time_t mdtmCurrent_alarm = 0; //20,22: ...and the current_alarm variable, which allows main to determine the expiration time of the alarm on which alarm_thread is currently waiting. The current_alarm variable is an optimization — main does not need to awaken alarm_thread unless it is either idle, or waiting for an alarm later than the one main has just inserted.

void printTimespec(void) { //timespec_get @ http://en.cppreference.com/w/c/chrono/timespec_get
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	char buff[100];
	strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
	printf("\nThread: %lu. Time: %s.%09ld. ", pthread_self(), buff, ts.tv_nsec);
}

void alarm_insert(alarm_t* sttAlarm) { // Insert alarm entry on list, in order. //Part 2 shows the new function alarm_insert. This function is nearly the same as the list insertion code from alarm_mutex.c, except that it signals the condition variable alarm_cond when necessary. I made alarm_insert a separate function because now it needs to be called from two places — once by main to insert a new alarm, and now also by alarm_thread to reinsert an alarm that has been "preempted" by a new earlier alarm.
	int intStatus;
	alarm_t **sttLast, *sttNext;

	sttLast = &msttAlarm_list; //LOCKING PROTOCOL: This routine requires that the caller have locked the alarm_mutex! //9-14 I have recommended that mutex locking protocols be documented, and here is an example: The alarm_insert function points out explicitly that it must be called with the alarm_mutex locked.
	sttNext = *sttLast;
	while (sttNext != NULL) {
		if (sttNext->time >= sttAlarm->time) { ////////////
			sttAlarm->link = sttNext;/*1*//*(3 sec)->link = 10 sec*/
			*sttLast = sttAlarm; /*2*//*msttAlarm_list.seconds = 3*/
			break;
		}
		sttLast = &sttNext->link;
		sttNext = sttNext->link;
	}
	if (sttNext == NULL) { //If we reached the end of the list, insert the new alarm there.("next" is NULL, and "last" points to the link field of the last item, or to the list header.)
		*sttLast = sttAlarm;
		sttAlarm->link = NULL;
	}
#ifdef DEBUG
	tprintf("[list: ");
	for(sttNext = msttAlarm_list; sttNext != NULL; sttNext = sttNext->link)
		printf("%d(%d)[\"%s\"] ", sttNext->time, sttNext->time - time(NULL), sttNext->message);
	printf("]\n");
#endif	
	if (mdtmCurrent_alarm == 0 || sttAlarm->time < mdtmCurrent_alarm) { //48-53: If current_alarm(the time of the next alarm expiration) is 0. then the alarm_thread is not aware of any outstanding alarm requests, and is waiting for new work. If current_alarm has a time greater than the expiration time of the new alarm, then alarm_thread is not planning to look for new work soon enough to handle the new alarm. In either case, signal the alarm_cond condition variable so that alarm_thread will wake up and process the new alarm. //Wake the alarm thread if it is not busy(that is, if current_alarm is 0, signifying that it's waiting for work), or if the new alarm comes before the one on which the alarm thread is waiting.
		mdtmCurrent_alarm = sttAlarm->time; /*3*//*3 sec*/
		intStatus = pthread_cond_signal(&msttAlarm_cond); if (intStatus != 0) err_abort(intStatus, "Signal cond");
	} //53
}

void* alarm_thread(void* arg) { // The alarm thread's start routine. //Part 3 shows the alarm_thread function, the start function for the "alarm server" thread. The general structure of alarm_thread is very much like the alarm_thread in alarm_mutex.c. The differences are due to the addition of the condition variable.
	alarm_t* sttAlarm;
	struct timespec sttCond_time; //Structure holding an interval broken down into seconds and nanoseconds. @ http://en.cppreference.com/w/c/chrono/timespec
	time_t dtmNow;
	int intStatus, intExpired;

	intStatus = pthread_mutex_lock(&msttAlarm_mutex); if (intStatus != 0) err_abort(intStatus, "Lock mutex"); //Loop forever, processing commands. The alarm thread will be disintegrated when the process exits. Lock the mutex at the start — it will be unlocked during condition waits, so the main thread can insert alarms.
	while (1) {
		mdtmCurrent_alarm = 0; //26 //26-31 If the alarm_list is empty, alarm_mutex.c could do nothing but sleep anyway, so that main would be able to process a new command. The result was that it could not see a new alarm request for at least a full second. Now, alarm_thread instead waits on the alarm_cond condition variable, with no timeout. It will "sleep" until you enter a new alarm command, and then main will be able to awaken it immediately. Setting current_alarm to 0 tells main that alarm_thread is idle. Remember that pthread_cond_wait unlocks the mutex before waiting, and relocks the mutex before returning to the caller. //If the alarm list is empty, wait until an alarm is added. Setting current_alarm to 0 informs the insert routine that the thread is not busy.
		while (msttAlarm_list == NULL) { //The predicate loop. It is important that you test the predicate after locking the appropriate mutex and before waiting on the condition variable. It is equally important that you test the predicate again when the thread wakes up. You should always wait for a condition variable in a loop, to protect against program errors, multiprocessor races, and spurious wakeups.
			intStatus = pthread_cond_wait(&msttAlarm_cond, &msttAlarm_mutex); if (intStatus != 0) err_abort(intStatus, "Wait on cond"); //printTimespec(); printf( "alarm_thread 222: (msttAlarm_list == NULL) = %s\n", ((msttAlarm_list == NULL) ? "true" : "false") );
		} //31
		sttAlarm = msttAlarm_list;
		msttAlarm_list = sttAlarm->link;
		dtmNow = time(NULL);
		intExpired = 0; //35 The new variable expired is initialized to 0; it will be set to 1 later if the timed condition wait expires. This makes it a little easier to decide whether to print the current alarm's message at the bottom of the loop.
		if (sttAlarm->time > dtmNow) { //36-42 If the alarm we've just removed from the list hasn't already expired, then we need to wait for it. Because we're using a timed condition wait, which requires a POSIX.1b struct timespec, rather than the simple integer time required by sleep, we convert the expiration time. This is easy, because a struct timespec has two members—tv_sec is the number of seconds since the Epoch, which is exactly what we already have from the time function, and tv_nsec is an additional count of nanoseconds. We will just set tv_nsec to 0, since we have no need of the greater resolution.
#ifdef DEBUG
			printf("[waiting: %d(%d)\"%s\"]\n", sttAlarm->time, sttAlarm->time - time(NULL), sttAlarm->message);
#endif
			sttCond_time.tv_sec = sttAlarm->time;
			sttCond_time.tv_nsec = 0; //42
			mdtmCurrent_alarm = sttAlarm->time; //43 Record the expiration time in the current_alarm variable so that main can determine whether to signal alarm_cond when a new alarm is added.
			while (mdtmCurrent_alarm == sttAlarm->time) { //44-53 Wait until either the current alarm has expired, or main requests that alarm_ thread look for a new, earlier alarm. Notice that the predicate test is split here, for convenience. The expression in the while statement is only half the predicate, detecting that main has changed current_alarm by inserting an earlier timer. When the timed wait returns ETIMEDOUT, indicating that the current alarm has expired, we exit the while loop with a break statement at line 49.
				intStatus = pthread_cond_timedwait(&msttAlarm_cond, &msttAlarm_mutex, &sttCond_time);
				if (intStatus == ETIMEDOUT) {
					intExpired = 1;
					break;
				}
				if (intStatus != 0) err_abort(intStatus, "Cond timedwait");
			} //53
			if (!intExpired) //54-55 If the while loop exited when the current alarm had not expired, main must have asked alarm_thread to process an earlier alarm. Make sure the current alarm isn't lost by reinserting it onto the list.
				alarm_insert(sttAlarm);/*4*//*5 sec*/ //55
		} else
			intExpired = 1; //57 If we remove from alarm_list an alarm that has already expired, just set the expired variable to 1 to ensure that the message is printed.
		if (intExpired) {
			printf("(%d) %s\n", sttAlarm->seconds, sttAlarm->message);
			free(sttAlarm);
		}
	}
}

int main(int argc, char* argv[]) { //Part 4 shows the final section of alarm_cond.c, the main program. It is nearly identical to the main function from alarm_mutex.c.
	int intStatus;
	char line[128];
	alarm_t* sttAlarm;
	pthread_t lngThread;

	intStatus = pthread_create(&lngThread, NULL, alarm_thread, NULL); if (intStatus != 0) err_abort(intStatus, "Create alarm thread");
	while (1) {
		printf("Alarm> ");
		if (fgets(line, sizeof(line), stdin) == NULL) exit(0);
		if (strlen(line) <= 1) continue;
		sttAlarm = (alarm_t*)malloc(sizeof(alarm_t)); if (sttAlarm == NULL) errno_abort("Allocate alarm");
		if (sscanf(line, "%d %64[^\n]", &sttAlarm->seconds, sttAlarm->message) < 2) { fprintf(stderr, "Bad command\n"); free(sttAlarm); //Parse input line into seconds(%d) and a message(%64[^\n]), consisting of up to 64 characters separated from the seconds by whitespace.
		} else {
			intStatus = pthread_mutex_lock(&msttAlarm_mutex); if (intStatus != 0) err_abort(intStatus, "Lock mutex");
			sttAlarm->time = time(NULL) + sttAlarm->seconds;
			alarm_insert(sttAlarm); //38 Because the condition variable signal operation is built into the new alarm_insert function, we call alarm_insert rather than inserting a new alarm directly. //Insert the new alarm into the list of alarms, sorted by expiration time.
			intStatus = pthread_mutex_unlock(&msttAlarm_mutex); if (intStatus != 0) err_abort(intStatus, "Unlock mutex");
		}
	}
}
//printf( "alarm_insert 222: (msttAlarm_list == NULL) = %s\n", ((msttAlarm_list == NULL) ? "true" : "false") );
