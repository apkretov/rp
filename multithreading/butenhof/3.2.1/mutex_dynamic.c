//Often you cannot initialize a mutex statically. Then you will need to call pthread_mutex_init to initialize the mutex dynamically.
#include <pthread.h>
#include "errors.h"

//It is a good idea to associate a mutex clearly with the data it protects, if possible, by keeping the definition of the mutex and data together.
typedef struct my_struct_tag { //Define a structure, with a mutex.
	pthread_mutex_t mutex; // Protects access to value
	int value; // Access protected by mutex
} my_struct_t;

int main(int argc, char *argv[]) {
	my_struct_t* data;
	int status;

	data = malloc(sizeof(my_struct_t));
	if (data == NULL)
		errno_abort("Allocate structure");
	status = pthread_mutex_init(&data->mutex, NULL);
	if (status != 0)
		err_abort(status, "Init mutex");
	//It is safe to destroy a mutex when you know that no threads can be blocked on the mutex, and no additional threads will try to lock the mutex. The best way to know this is usually within a thread that has just unlocked the mutex, when program logic ensures that no threads will try to lock the mutex later. When a thread locks a mutex within some heap data structure to remove the structure from a list and free the storage, for example, it is safe (and a good idea) to unlock and destroy the mutex before freeing the storage that the mutex occupies.
	status = pthread_mutex_destroy(&data->mutex); //When you no longer need a mutex that you dynamically initialized by calling pthread_mutex_init, you should destroy the mutex by calling pthread_mutex_ destroy.
	if (status != 0)
		err_abort(status, "Destroy mutex");
	(void)free(data);
	return status;
}
