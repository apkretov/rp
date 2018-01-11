//Thread Synchronization - Mutexes @ http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html#SYNCHRONIZATION
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

void* functionC(void*) {
   pthread_mutex_lock(&mutex1);
   counter++;
   printf("Counter value: %d\n", counter);
   pthread_mutex_unlock(&mutex1);
}

main() {
   int rc1, rc2;
   pthread_t thread1, thread2;
   if ( (rc1=pthread_create(&thread1, NULL, &functionC, NULL)) ) // Create independent threads each of which will execute functionC
      printf("Thread creation failed: %d\n", rc1);
   if ( (rc2=pthread_create(&thread2, NULL, &functionC, NULL)) )
      printf("Thread creation failed: %d\n", rc2);
   pthread_join(thread1, NULL); //Wait till threads are complete before main continues. Unless we wait we run the risk of executing an exit which will terminate the process and all threads before the threads have completed.
   pthread_join(thread2, NULL);
   exit(0);
}

