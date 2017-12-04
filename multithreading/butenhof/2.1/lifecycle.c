#include <pthread.h>
#include "errors.h"

void* thread_routine(void* arg) { //Thread start routine.
	return arg; //It is a good idea for all thread functions to return something, even if it is simply NULL. If you omit the return statement, pthread_join will still return some value—whatever happens to be in the place where the thread's start function would have stored a return value (probably a register).
}

int main(int argc, char* argv[]) {
	pthread_t thread_id;
	void* thread_result;
	int status;

	status = pthread_create(&thread_id, NULL, thread_routine, NULL);
	if (status != 0)
		err_abort(status, "Create thread");

	status = pthread_join(thread_id, &thread_result);
	if (status != 0)
		err_abort (status, "Join thread");
	if (thread_result == NULL)
		return 0;
	else
		return 1;
}
