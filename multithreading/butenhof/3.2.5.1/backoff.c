//The program demonstrates how to avoid mutex deadlocks by applying a backoff algorithm. The program creates two threads, one running function lock_forward and the other running function lock_backward. The two threads loop ITERATIONS times, each iteration attempting to lock all of three mutexes in sequence. The lock_forward thread locks mutex 0, then mutex 1, then mutex 2, while lock_backward locks the three mutexes in the opposite order. Without special precautions, this design will always deadlock quickly.
#include <pthread.h>
#include "errors.h"
#define ITERATIONS 10

pthread_mutex_t mutex[3] = { PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER }; //Initialize a static array of 3 mutexes.

int backoff = 1; //Whether to backoff or deadlock //15 You can see the deadlock by running the program as backoff 0. The first argument is used to set the backoff variable. If backoff is 0, the two threads will use pthread_mutex_lock to lock each mutex. Because the two threads are starting from opposite ends, they will crash in the middle, and the program will hang. When backoff is nonzero, the threads use pthread_mutex_trylock, which enables the backoff algorithm. When the mutex lock fails with EBUSY, the thread will release all mutexes it currently owns, and start over.
int yield_flag = 0; // 0: no yield, >0: yield, <0: sleep //16 It is possible that, on some systems, you may not see any mutex collisions, because one thread is always able to lock all mutexes before the other thread has a chance to lock any. You can resolve that problem by setting the yield_flag variable, which you do by running the program with a second argument, for example, backoff 1. When yield_flag is 0, which it is unless you specify a second argument, each thread's mutex locking loop may run uninterrupted, preventing a deadlock. When yield_flag has a value greater than 0, however, the threads will call sched_yield after locking each mutex, ensuring that the other thread has a chance to run. And if you set yield_flag to a value less than 0, the threads will sleep for one second after locking each mutex, to be really sure the other thread has a chance to run.

void* lock_forward (void* arg) { //This is a thread start routine that locks all mutexes in order, to ensure a conflict with lock reverse, which does the opposite.
	int i, iterate, backoffs;
	int status;
	for (iterate = 0; iterate < ITERATIONS; iterate++) {
		backoffs = 0;
		for (i = 0; i < 3; i++) {
			if (i == 0) {
				status = pthread_mutex_lock(&mutex[i]); if (status != 0) err_abort(status, "First lock");
			} else {
				if (backoff)
					status = pthread_mutex_trylock(&mutex[i]);
				else
					status = pthread_mutex_lock(&mutex[i]);
				if (status == EBUSY) {
					backoffs++;
					DPRINTF((" [forward locker backing off at %d]\n", i));
					for (; i >= 0; i--) { //You are free to unlock the mutexes in whatever order makes the most sense. Unlocking mutexes cannot result in deadlock. If you use a "try and back off algorithm, however, you should always try to release the mutexes in reverse order. If you unlock mutex 1 and mutex 2 while mutex 3 is still locked, another thread may have to lock both mutex 1 and mutex 2 before finding it cannot lock the entire hierarchy, at which point it will have to unlock mutex 2 and mutex 1, and then retry. Unlocking in reverse order reduces the chance that another thread will need to back off.
						status = pthread_mutex_unlock(&mutex[i]); if (status != 0) err_abort(status, "Backoff");
					}
				} else {
					if (status != 0)
						err_abort(status, "Lock mutex");
					DPRINTF((" forward locker got %d\n", i));
				}
			}
			if (yield_flag) { //Yield processor, if needed to be sure locks get interleaved on a uniprocessor. //In my case, it is needed on my PC.
				if (yield_flag > 0)
					sched_yield();
				else
					sleep(1);
			}
		}

		printf ("lock forward got all locks, %d backoffs\n", backoffs); //Report that we got 'em, and unlock to try again. //70-75 After locking all of the three mutexes, each thread reports success, and tells how many times it had to back off before succeeding. On a multiprocessor, or when you've set yield_flag to a nonzero value, you'll usually see a lot more nonzero backoff counts. The thread unlocks all three mutexes, in the reverse order of locking, which helps to avoid unnecessary backoffs in other threads. Calling sched_yield at the end of each iteration "mixes things up" a little so one thread doesn't always start each iteration first. The sched_yield function is described in Section 5.5.2.
		pthread_mutex_unlock(&mutex[2]);
		pthread_mutex_unlock(&mutex[1]);
		pthread_mutex_unlock(&mutex[0]);
		sched_yield(); //75
	}
	return NULL;
}

void* lock_backward (void* arg) { //This is a thread start routine that locks all mutexes in reverse order, to ensure a conflict with lock_forward, which does the opposite.
	int i, iterate, backoffs;
	int status;
	for (iterate = 0; iterate < ITERATIONS; iterate++) {
		backoffs = 0;
		for (i = 2; i >= 0; i--) {
			if (i == 2) {
				status = pthread_mutex_lock(&mutex[i]); if (status != 0) err_abort(status, "First lock");
			} else {
				if (backoff)
					status = pthread_mutex_trylock (&mutex[i]);
				else
					status = pthread_mutex_lock (&mutex[i]);
				if (status == EBUSY) {
					backoffs++;
					DPRINTF((" [backward locker backing off at %d]\n", i));
					for (; i < 3; i++) {
						status = pthread_mutex_unlock (&mutex[i]); if (status != 0) err_abort(status, "Backoff");
					}
				} else {
					if (status != 0)
						err_abort(status, "Lock mutex");
					DPRINTF((" backward locker got %d\n", i));
				}
			}

			if (yield_flag) { //Yield processor, if needed to be sure locks get interleaved on a uniprocessor.
				if (yield_flag > 0)
					sched_yield();
				else
					sleep(1);
			}
		}
		printf("lock backward got all locks, %d backoffs\n", backoffs); //Report that we got 'em, and unlock to try again.
		pthread_mutex_unlock(&mutex[0]);
		pthread_mutex_unlock(&mutex[1]);
		pthread_mutex_unlock(&mutex[2]);
		sched_yield();
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t forward, backward;
	int status;	printf("111 argc: %d argv[0]: %s backoff: %d\n", argc, argv[0], backoff);

	if (argc > 1) { //If the first argument is absent, or nonzero, a backoff algorithm will be used to avoid deadlock. If the first argument is zero, the program will deadlock on a lock "collision."
		backoff = atoi(argv[1]); printf("222 backoff = atoi(argv[1]): %d\n", atoi(argv[1])); }
	if (argc > 2) { //If the second argument is absent, or zero, the two threads run "at speed." On some systems, especially uniprocessors, one thread may complete before the other has a chance to run, and you won't see a deadlock or backoffs. In that case, try running with the argument set to a positive number to cause the threads to call sched_yield() at each lock; or, to make it even more obvious, set to a negative number to cause the threads to call sleep(l) instead.
		yield_flag = atoi(argv[2]); printf("333 yield_flag = atoi(argv[2]): %d\n", atoi(argv[2])); }	printf("444\n");

	status = pthread_create(&forward, NULL, lock_forward, NULL); if (status != 0)	err_abort(status, "Create forward");
	status = pthread_create(&backward, NULL, lock_backward, NULL);	if (status != 0) err_abort(status, "Create backward");

	//If you want to terminate the initial thread while allowing other threads in the process to continue running, call pthread_exit instead of returning from main. 2.2.2 Startup @ file:///home/alex/rp/multithreading/butenhof/book/Butenhof_Programming_with_POSIX%C2%AE_Threads.html
	//If main() finishes before the threads it has created, and exits with pthread_exit(), the other threads will continue to execute. Otherwise, they will be automatically terminated when main() finishes. Terminating Threads @ https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
	pthread_exit(NULL);
}
