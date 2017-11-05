//Passing Arguments to Threads @ https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

struct thread_data {
   int  thread_id;
   char* message;
};

void* PrintHello(void* threadarg) {
   /*ORIG struct*/ thread_data* my_data;
   my_data = (/*ORIG struct*/ thread_data*) threadarg;
   cout << "Thread ID: " << my_data->thread_id ;
   cout << ". Message: " << my_data->message << endl;
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   /*ORIG struct*/ thread_data td[NUM_THREADS];
   int rc;
   int i;
   for (i = 0; i < NUM_THREADS; i++) {
      cout << "main(): Creating thread " << i << ".\n";
      td[i].thread_id = i;
      td[i].message = "This is message.";
      rc = pthread_create(&threads[i], NULL, PrintHello, (void*)&td[i]);
      if (rc) {
         cout << "Error: unable to create thread, " << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
