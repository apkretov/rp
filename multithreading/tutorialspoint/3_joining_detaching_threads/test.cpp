//Joining and Detaching Threads @ https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;
#include <stdio.h>

#define NUM_THREADS 5

void* wait(void* t) {
   int i;
   long tid;
   tid = (long)t;
   printf("Sleeping in thread %li...\n", tid);
   sleep(1);
   printf("Thread with id %li exiting.\n", tid);
   pthread_exit(NULL);
}

int main() {
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void* status;
   pthread_attr_init(&attr); //Initialize thread
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //Set thread joinable
   for (i = 0; i < NUM_THREADS; i++) {
      printf("main(): Creating thread %i.\n", i);
      rc = pthread_create(&threads[i], NULL, wait, (void*)i);
      if (rc) {
         cout << "Error: unable to create thread " << rc << endl;
         exit(-1);
      }
   }
   pthread_attr_destroy(&attr); // free attribute and wait for the other threads
   for (i = 0; i < NUM_THREADS; i++) {
      printf("main(): Joining thread id %i...\n", i); //TEST
      rc = pthread_join(threads[i], &status);
      if (rc) {
         cout << "Error: unable to join," << rc << endl;
         exit(-1);
      }
      printf("main(): Joined thread id %i, exiting with status %lu.\n", i, (long)status);
   }
   cout << "main(): Program exiting.\n";
   pthread_exit(NULL);
}
