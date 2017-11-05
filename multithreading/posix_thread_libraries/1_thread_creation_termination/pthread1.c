//Thread Creation and Termination @ http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html#SCHEDULING
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message_function(void* ptr) {
     char* message;
     message = (char*) ptr;
     printf("%s \n", message);
} //Threads terminate by explicitly calling pthread_exit, by letting the function return, or by a call to the function exit which will terminate the process including any threads.

main() {
     pthread_t thread1, thread2;
     char* message1 = "Thread 1";
     char* message2 = "Thread 2";
     int  iret1, iret2;
     iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1); //Create independent threads each of which will execute function
     iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);
     pthread_join(thread1, NULL); //Wait till threads are complete before main continues. Unless we wait we run the risk of executing an exit which will terminate the process and all threads before the threads have completed.
     pthread_join(thread2, NULL);
     printf("Thread 1 returns: %d\n", iret1);
     printf("Thread 2 returns: %d\n", iret2);
     exit(0);
}
