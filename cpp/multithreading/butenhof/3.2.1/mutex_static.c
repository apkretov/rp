#include <pthread.h>
#include "errors.h"

typedef struct my_struct_tag { // Declare a structure, with a mutex, statically initialized. This is the same as using pthread_mutex_init, with the default attributes. //It is a good idea to associate a mutex clearly with the data it protects, if possible, by keeping the definition of the mutex and data together. //Most of the time you'll probably declare mutexes using extern or static storage class, at "file scope," that is, outside of any function. When you declare a static mutex that has default attributes, you should use the PTHREAD_MUTEX_INITIALIZER macro.
	pthread_mutex_t mutex; //Protects access to value
	int value; //Access protected by mutex
} my_struct_t;
my_struct_t data = { PTHREAD_MUTEX_INITIALIZER, 0 }; //You do not need to destroy a mutex that was statically initialized using the PTHREAD_MUTEX_INITIALIZER macro.

int main (int argc, char *argv[]) {
	return 0;
}
