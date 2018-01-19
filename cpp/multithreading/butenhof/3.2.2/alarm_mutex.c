#include <pthread.h>
#include <time.h>
#include "errors.h"

typedef struct alarm_tag { //The "alarm" structure now contains the time_t for each alarm, so that they can be sorted. Storing the requested number of seconds would not be enough, since the "alarm thread" cannot tell how long it has been on the list.
	struct alarm_tag* link;
	int seconds;
	time_t time; //seconds from EPOCH
	char message[64];
} alarm_t;

pthread_mutex_t alarm_mutex = PTHREAD_MUTEX_INITIALIZER;
alarm_t* alarm_list = NULL;

void* alarm_thread(void* arg) { //The alarm thread's start routine.
	alarm_t* alarm;
	int sleep_time;
	time_t now;
	int status;
	while (1) { //Loop forever, processing commands. The alarm thread will be disintegrated when the process exits.
		status = pthread_mutex_lock(&alarm_mutex);

		if (status != 0) err_abort(status, "Lock mutex");
		alarm = alarm_list;
		if (alarm == NULL) { //If the alarm list is empty, wait for one second. This allows the main thread to run, and read another command. If the list is not empty, remove the first item. Compute the number of seconds to wait — if the result is less than 0 (the time has passed), then set the sleep_time to 0.
			sleep_time = 1;
		} else { //31-42
			alarm_list = alarm->link; //31-42: If an alarm is found, it is removed from the list.
			now = time(NULL); //31-42: The current time is retrieved by calling the time function,
			if (alarm->time <= now) //31-42: and it is compared to the requested time for the alarm.
				sleep_time = 0; //31-42: If the alarm has already expired, then alarm_thread will set sleep_time to 0.
			else //31-42: If the alarm has not expired,
				sleep_time = alarm->time - now; //31-42: alarm_thread computes the difference between the current time and the alarm expiration time, and sets sleep_time to that number of seconds.
			#ifdef DEBUG
				printf("[waiting: %d(%d)\"%s\"]\n", alarm->time, sleep_time, alarm->message);
			#endif
		} //42		

		status = pthread_mutex_unlock (&alarm_mutex); /*52-58: The mutex is always unlocked before sleeping or yielding. If the mutex remained locked, then main would be unable to insert a new alarm on the list. That would make the program behave synchronously—the user would have to wait until the alarm expired before doing anything else.*/ /*Unlock the mutex before waiting, so that the main thread can lock it to insert a new alarm request. If the sleep_time is 0, then call sched_yield, giving the main thread a chance to run if it has been readied by user input, without delaying the message if there's no input.*/ if (status != 0) err_abort (status, "Unlock mutex");
		if (sleep_time > 0)
			sleep(sleep_time); //52-58: Calling sleep blocks alarm_thread for the required period of time—it cannot run until the timer expires.
		else //52-58: Calling sched_yield will yield the processor to a thread that is ready to run, but will return immediately if there are no ready threads. In this case, it means that the main thread will be allowed to process a user command if there's input waiting—but if the user hasn't entered a command, sched_yield will return immediately.
			sched_yield(); //58
		if (alarm != NULL) { //If a timer expired, print the message and free the structure.
			printf ("(%d) %s\n", alarm->seconds, alarm->message);
			free(alarm);
		}
	}
}

int main(int argc, char *argv[]) { //Each request is queued to a server thread, alarm_thread. As soon as main has queued the request, it is free to read the next command.
	int status;
	char line[128];
	alarm_t *alarm, **last, *next; // '**' is declaring a pointer to a pointer to an int. Such an object can be used for a 2D array (basically an array of arrays). @ http://www.cplusplus.com/forum/general/103523/
	pthread_t thread;
	status = pthread_create(&thread, NULL, alarm_thread, NULL); /*8-11: Create the server thread that will process all alarm requests.*/ if (status != 0) err_abort (status, "Create alarm thread"); /*11*/
	while (1) {
		printf("alarm> "); //13-28: Read and process a command, much as in any of the other versions of our alarm program. As in alarm_thread.c, the data is stored in a heap structure allocated by malloc.
		if (fgets(line, sizeof(line), stdin) == NULL) exit (0);
		if (strlen (line) <= 1) continue;
		alarm = (alarm_t*)malloc(sizeof(alarm_t)); if (alarm == NULL) errno_abort("Allocate alarm");
		if (sscanf(line, "%d %64[^\n]", &alarm->seconds, alarm->message) < 2) { //Parse input line into seconds (%d) and a message (%64[^\n]), consisting of up to 64 characters separated from the seconds by whitespace.
			fprintf(stderr, "Bad command\n");
			free(alarm); //28
		} else {
			status = pthread_mutex_lock(&alarm_mutex); /*30-32: The program needs to add the alarm request to alarm_list, which is shared by both alarm_thread and main. So we start by locking the mutex that synchronizes access to the shared data, alarm_mutex.*/ if (status != 0) err_abort(status, "Lock mutex"); /*32*/

			alarm->time = time(NULL) + alarm->seconds; //33 Because alarm_thread processes queued requests, serially, it has no way of knowing how much time has elapsed between reading the command and processing it. Therefore, the alarm structure includes the absolute time of the alarm expiration, which we calculate by adding the alarm interval, in seconds, to the current number of seconds since the UNIX Epoch, as returned by the time function.
			last = &alarm_list; //39-49: The alarms are sorted in order of expiration time on the alarm_list queue. //Insert the new alarm into the list of alarms, sorted by expiration time.
			next = /*ORIG: *last*/ /*TEST:*/alarm_list;
			while (next != NULL) { //39-49: The insertion code searches the queue
				if (next->time >= alarm->time) { //39-49: until it finds the first entry with a time greater than or equal to the new alarm's time.
					alarm->link = next; //39-49: The new entry is inserted preceding the located entry.
					*last = alarm; //39-49: Because alarm_list is a simple linked list, the traversal maintains a current entry pointer (this) and a pointer to the previous entry's link member, or to the alarm_list head pointer (last).
					break;
				}
				last = &next->link;
				next = next->link;
			} //49
			if (next == NULL) { //56-59: If no alarm with a time greater than or equal to the new alarm's time is found, //If we reached the end of the list, insert the new alarm there, ("next" is NULL, and "last" points to the link field of the last item, or to the list header).
				*last = alarm; //56-59: then the new alarm is inserted at the end of the list. That is, if the alarm pointer is NULL on exit from the search loop (the last entry on the list always has a link pointer of NULL), the previous entry (or queue head) is made to point to the new entry.
				alarm->link = NULL;
			} //59

			#ifdef DEBUG
				printf ("[list: ");
				for (next = alarm_list; next != NULL; next = next->link)
					printf ("%d(%d)[\"%s\"] ", next->time, next->time - time (NULL), next->message);
				printf ("]\n");
			#endif
			status = pthread_mutex_unlock (&alarm_mutex); if (status != 0) err_abort (status, "Unlock mutex");
		}
	}
}
