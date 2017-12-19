#include <pthread.h>
#include "errors.h"
#include <unistd.h> //Sleep for milliseconds @ https://stackoverflow.com/questions/4184468/sleep-for-milliseconds

#define SPIN 10000000 //4: This definition controls how long counter_thread holds the mutex while updating the counter. Making this number larger increases the chance that the pthread_mutex_trylock in monitor_thread will occasionally return EBUSY.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long counter;
time_t end_time;

// Thread start routine that repeatedly locks a mutex and increments a counter.
void* counter_thread(void* arg) { //14-39: The counter_thread wakes up approximately each second, locks the mutex, and spins for a while, incrementing counter. The counter is therefore increased by SPIN each second.
	int status;
	int spin;
	while (time(NULL) < end_time) { // Until end_time, increment the counter each second. Instead of just incrementing the counter, it sleeps for another second with the mutex locked, to give monitor_thread a reasonable chance of running.
		status = pthread_mutex_lock(&mutex); if (status != 0) err_abort(status, "Lock mutex");
		for (spin = 0; spin < SPIN; spin++)
			counter++;
		status = pthread_mutex_unlock(&mutex);	if (status != 0) err_abort(status, "Unlock mutex");
		/*ORIG sleep(1)*/ usleep(1e5); //Sleep for milliseconds @ https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
	}
	printf("Counter is %#lx\n", counter);
	return NULL; //39
}

//Thread start routine to "monitor" the counter. Every 3 seconds, try to lock the mutex and read the counter. If the trylock fails, skip this cycle.
void* monitor_thread(void* arg) { //46-72: The monitor_thread wakes up every three seconds, and tries to lock the mutex. If the attempt fails with EBUSY, monitor_thread counts the failure and waits another three seconds. If the pthread_mutex_trylock succeeds, then monitor_thread prints the current value of counter (scaled by SPIN).
	int status;
	int misses = 0;
	while (time(NULL) < end_time) { //Loop until end_time, checking the counter every 3 seconds.
		/*ORIG sleep(3)*/ usleep(1e5); //Sleep for milliseconds @ https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
		status = pthread_mutex_trylock(&mutex);
		if (status != EBUSY) { if (status != 0) err_abort(status, "Trylock mutex");
			printf("Counter is %ld\n", counter / SPIN);
			status = pthread_mutex_unlock(&mutex); if (status != 0) err_abort(status, "Unlock mutex");
		} else
			misses++; //Count "misses" on the lock
	}
	printf("Monitor thread missed update %d times.\n", misses);
	return NULL; //72
}

int main(int argc, char* argv[]) {
	int status;
	pthread_t counter_thread_id;
	pthread_t monitor_thread_id;
	{
		#ifdef sun //80-88: On Solaris 2.5, call thr_setconcurrency to set the thread concurrency level to 2. This allows the counter_thread and monitor_thread to run concurrently on a uniprocessor. Otherwise, monitor_thread would not run until counter_ thread terminated.
			//On Solaris 2.5, threads are not timesliced. To ensure that our threads can run concurrently, we need to increase the concurrency level to 2.
			DPRINTF(("Setting concurrency level to 2\n"));
			thr_setconcurrency(2);
		#endif //88
	}
	end_time = time(NULL) + /*ORIG 60*/ 5; //Run for 1 minute
	status = pthread_create(&counter_thread_id, NULL, counter_thread, NULL);		if (status != 0) err_abort(status, "Create counter thread");
	status = pthread_create(&monitor_thread_id, NULL, monitor_thread, NULL);		if (status != 0)	err_abort(status, "Create monitor thread");
	status = pthread_join(counter_thread_id, NULL);											if (status != 0) err_abort(status, "Join counter thread");
	status = pthread_join(monitor_thread_id, NULL);											if (status != 0) err_abort(status, "Join monitor thread");
	return 0;
}
