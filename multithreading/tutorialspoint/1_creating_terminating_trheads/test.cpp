//C++ Multithreading @ https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

void* PrintHello(void* threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL); //Here pthread_exit is used to explicitly exit a thread. Typically, the pthread_exit() routine is called after a thread has completed its work and is no longer required to exist.
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   long i;
   for (i = 0; i < NUM_THREADS; i++) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void*)i /*A single argument that may be passed to start_routine. It must be passed by reference as a pointer cast of type void. NULL may be used if no argument is to be passed.*/);
      if (rc) {
         cout << "Error: unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL); //If main() finishes before the threads it has created, and exits with pthread_exit(), the other threads will continue to execute. Otherwise, they will be automatically terminated when main() finishes.
}
