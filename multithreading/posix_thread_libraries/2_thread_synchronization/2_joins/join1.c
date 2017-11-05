//Thread Synchronization - Joins @ http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html#SYNCHRONIZATION
#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

void* thread_function(void* dummyPtr) {
   printf("Thread number %ld\n", pthread_self());
   pthread_mutex_lock(&mutex1);
   counter++;
   pthread_mutex_unlock(&mutex1);
}

main() {
   pthread_t thread_id[NTHREADS];
   int i, j;
   for(i=0; i < NTHREADS; i++)
      pthread_create(&thread_id[i], NULL, thread_function, NULL);
   for(j=0; j < NTHREADS; j++)
      pthread_join(thread_id[j], NULL);
   printf("Final counter value: %d\n", counter); //Now that all threads are complete I can print the final result. Without the join I could be printing a value before all the threads have been completed.                                                */
}
