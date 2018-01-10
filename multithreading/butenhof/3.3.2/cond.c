#include <pthread.h>
#include <time.h>
#include "errors.h"

typedef struct my_struct_tag {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int value;
} my_struct_t;
my_struct_t data = { PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0 };

int hibernation = 1; //Default to 1 second

//Thread start routine. It will set the main thread's predicate and signal the condition variable.
void* wait_thread(void* arg) { //20-37 The wait_thread sleeps for a short time to allow the main thread to reach its condition wait before waking it, sets the shared predicate (data.value), and then signals the condition variable. The amount of time for which wait_thread will sleep is controlled by the hibernation variable, which defaults to one second.
	int status;
	sleep(hibernation); printf("wait_thread 1 \t Before pthread_mutex_lock. \n");

	status = pthread_mutex_lock(&data.mutex); if (status != 0) err_abort(status, "Lock mutex"); printf("wait_thread 2 \t After pthread_mutex_lock. \n");

	data.value = 1; /*Set predicate*/ printf("wait_thread 3 \t Before pthread_cond_signal. \n");
	status = pthread_cond_signal(&data.cond); if (status != 0) err_abort(status, "Signal condition"); printf("wait_thread 4 \t After pthread_cond_signal. \n"); printf("wait_thread 5 \t Before pthread_mutex_unlock. \n"); //understanding of pthread_cond_wait() and pthread_cond_signal() @ https://stackoverflow.com/questions/16522858/understanding-of-pthread-cond-wait-and-pthread-cond-signal

	status = pthread_mutex_unlock(&data.mutex); if (status != 0) err_abort(status, "Unlock mutex"); printf("wait_thread 6 \t After pthread_mutex_unlock. \n");

	return NULL;
} //37

int main(int argc, char* argv[]) { //Protects access to value. Signals change to value. Access protected by mutex.
	int status;
	pthread_t wait_thread_id;
	struct timespec timeout;
	// If an argument is specified, interpret it as the number of seconds for wait_thread to sleep before signaling the condition variable. You can play with this to see the condition wait below time out or wake normally.
	if (argc > 1) //51-52 If the program was run with an argument, interpret the argument as an integer value, which is stored in hibernation. This controls the amount of time for which wait_thread will sleep before signaling the condition variable.
		hibernation = atoi(argv[1]); //52

	status = pthread_create(&wait_thread_id, NULL, wait_thread, NULL); if (status != 0) err_abort(status, "Create wait thread"); //Create wait_thread.

	//Wait on the condition variable for 2 seconds, or until signaled by the wait_thread. Normally, wait_thread should signal. If you raise "hibernation" above 2 seconds, it will time out.
	timeout.tv_sec = time(NULL) + 2; //68-83 The main thread calls pthread_cond_timedwait to wait for up to two seconds. If hibernation has been set to a value of greater than two seconds, the condition wait will time out, returning ETIMEDOUT. If hibernation has been set to two, the main thread and wait_thread race, and, in principle, the result could differ each time you run the program. If hibernation is set to a value less than two, the condition wait should not time out.
	timeout.tv_nsec = 0; printf("main 1 \t\t Before pthread_mutex_lock. \n");

	status = pthread_mutex_lock(&data.mutex); printf("main 2 \t\t After pthread_mutex_lock. \n"); if (status != 0) err_abort(status, "Lock mutex");

	while (data.value == 0) { printf("main 3 \t\t Before pthread_cond_timedwait. \n");
		status = pthread_cond_timedwait(&data.cond, &data.mutex, &timeout); printf("main 4 \t\t After pthread_cond_timedwait. \n"); //understanding of pthread_cond_wait() and pthread_cond_signal() @ https://stackoverflow.com/questions/16522858/understanding-of-pthread-cond-wait-and-pthread-cond-signal
		if (status == ETIMEDOUT) {
			printf("Condition wait timed out. \n");
			break;
		}
		else if (status != 0) err_abort(status, "Wait on condition");
	} //83
	if (data.value != 0)
		printf("Condition was signaled. \n"); printf("main 5 \t\t Before pthread_mutex_unlock. \n");

	status = pthread_mutex_unlock(&data.mutex); printf("main 6 \t\t After pthread_mutex_unlock. \n"); if (status != 0) err_abort(status, "Unlock mutex");

	//TEST pthread_exit(NULL);
	return 0;
}
