#include <pthread.h>	//The program shows the pieces of a simple pipeline program. Each thread in the pipeline increments its input value by 1 and passes it to the next thread. The main program reads a series of "command lines" from stdin. A command line is either a number, which is fed into the beginning of the pipeline, or the character "=," which causes the program to read the next result from the end of the pipeline and print it to stdout.
#include "errors.h"

typedef struct stage_tag {		//9						//9-17 Each stage of a pipeline is represented by a variable of type stage_t.			//Internal structure describing a "stage" in the pipeline. One for each thread, plus a "result stage" where the final thread can stash the value.
	pthread_mutex_t mutex;		//Protect data			//9-17 stage_t contains a mutex to synchronize access to the stage (???).
	pthread_cond_t condAvail;	//Data available		//9-17 The avail condition variable is used to signal a stage that data is ready for it to process,
	pthread_cond_t condReady;	//Ready for data		//9-17 and each stage signals its own ready condition variable when it is ready for new data.
	int dataReady;					//Data present
	long data;						//Data to process		//9-17 The data member is the data passed from the previous stage,
	pthread_t thread;				//Thread for stage	//9-17 thread is the thread operating this stage,
	struct stage_tag* next;		//Next stage			//9-17 and next is a pointer to the following stage.
} stage_t;							//17

typedef struct pipe_tag {	//23							//23-29 The pipe_t structure describes a pipeline. It provides pointers to the first and last stage of a pipeline.		//External structure representing the entire pipeline.
	pthread_mutex_t mutex;	//Mutex to protect pipe
	stage_t* head;				//First stage				//23-29 The first stage, head, represents the first thread in the pipeline.
	stage_t* tail;				//Final stage				//23-29 The last stage, tail, is a special stage_t that has no thread—it is a place to store the final result of the pipeline.
	int stages;					//Number of stages
	int active;					//Active data elements
} pipe_t;						//29

int pipe_send(stage_t* sttStage, long lngData) { //Part 2 shows pipe_send, a utility function used to start data along a pipeline, and also called by each stage to pass data to the next stage.		//Internal function to send a "message" to the specified pipe stage. Threads use this to pass along the modified data item.
	int intStatus;
	intStatus = pthread_mutex_lock(&sttStage->mutex); if (intStatus != 0) return intStatus;
	while (sttStage->dataReady) { //17-23 It begins by waiting on the specified pipeline stage's ready condition variable until it can accept new data.			//If there's data in the pipe stage, wait for it to be consumed.
		intStatus = pthread_cond_wait(&sttStage->condReady, &sttStage->mutex);
		if (intStatus != 0) {
			pthread_mutex_unlock(&sttStage->mutex);
			return intStatus;
		}
	} //23
	sttStage->data = lngData; //28-30 Store the new data value, and then tell the stage that data is available.				//Send the new data
	sttStage->dataReady = 1;
	intStatus = pthread_cond_signal/*2.3*/(&sttStage->condAvail); /*30*/ if (intStatus != 0) { pthread_mutex_unlock(&sttStage->mutex); return intStatus; }
	intStatus = pthread_mutex_unlock(&sttStage->mutex);
	return intStatus;
}

void* pipe_stage(void* vrbArg) { //Part 3 shows pipe_stage, the start function for each thread in the pipeline. The thread's argument is a pointer to its stage_t structure.		//The thread start routine for pipe stage threads. Each will wait for a data item passed from the caller or the previous stage, modify the data and pass it along to the next (or final) stage.
	stage_t* sttStage = (stage_t*)vrbArg;
	stage_t* sttNextStage = sttStage->next;
	int intStatus;
	intStatus = pthread_mutex_lock(&sttStage->mutex); if (intStatus != 0) err_abort(intStatus, "Lock pipe stage");
	while (1) { //16-27 The thread loops forever, processing data. Because the mutex is locked outside the loop, the thread appears to have the pipeline stage's mutex locked all the time. However, it spends most of its time waiting for new data, on the avail condition variable. Remember that a thread automatically unlocks the mutex associated with a condition variable, while waiting on that condition variable. In reality, therefore, the thread spends most of its time with mutex unlocked.
		while (sttStage->dataReady != 1) {
			intStatus = pthread_cond_wait/*1.3*/(&sttStage->condAvail, &sttStage->mutex); if (intStatus != 0) err_abort(intStatus, "Wait for previous stage"); //A condition variable wait always returns with the mutex locked. @ 1. 3.3 Condition variables.
		}
		pipe_send/*3.1*/(sttNextStage, sttStage->data + 1); //22-26 When given data, the thread increases its own data value by one, and passes the result to the next stage. The thread then records that the stage no longer has data by clearing the dataReady flag, and signals the ready condition variable to wake any thread that might be waiting for this pipeline stage.
		sttStage->dataReady = 0;
		intStatus = pthread_cond_signal(&sttStage->condReady); if (intStatus != 0) err_abort(intStatus, "Wake next stage"); //26
	} //27 //Notice that the routine never unlocks the stage->mutex. The call to pthread_cond_wait implicitly unlocks the mutex while the thread is waiting, allowing other threads to make progress. Because the loop never terminates, this function has no need to unlock the mutex explicitly.			//Waiting on a condition variable atomically releases the associated mutex and waits until another thread signals the condition variable. The mutex must always be locked when you wait on a condition variable and, when a thread wakes up from a condition variable wait, it always resumes with the mutex locked. @ 3.3 Condition variables
}

int pipe_create(pipe_t* sttPipe, unsigned intStages) { //Part 4 shows pipe_create, the function that creates a pipeline. It can create a pipeline of any number of stages, linking them together in a list.			//External interface to create a pipeline. All the data is initialized and the threads created. They'll wait for data.
	stage_t **sttLink = &sttPipe->head/**/, *sttNewStage, *sttStage;
	int intStatus;
	intStatus = pthread_mutex_init(&sttPipe->mutex, NULL); if (intStatus != 0)	err_abort(intStatus, "Init pipe mutex");
	sttPipe->stages = intStages;
	sttPipe->active = 0;
	for (unsigned intPipeIndex = 0; intPipeIndex <= intStages; intPipeIndex++) { 	//18-34 For each stage, it allocates a new stage_t structure and initializes the members. Notice that one additional "stage" is allocated and initialized to hold the final result of the pipeline.
		sttNewStage = (stage_t*)malloc(sizeof(stage_t)); if (sttNewStage == NULL) errno_abort("Allocate stage");
		intStatus = pthread_mutex_init(&sttNewStage->mutex, NULL); if (intStatus != 0) err_abort(intStatus, "Init stage mutex");
		intStatus = pthread_cond_init(&sttNewStage->condAvail, NULL); if (intStatus != 0) err_abort(intStatus, "Init avail condition");
		intStatus = pthread_cond_init(&sttNewStage->condReady, NULL); if (intStatus != 0) err_abort(intStatus, "Init ready condition");
		sttNewStage->dataReady = 0;
		*sttLink = sttNewStage;/**//*The prior stage's next = sttNewStage*//**//*sttPipe->head = sttNewStage*/
		sttLink = &sttNewStage->next;/**/
	} //34
	*sttLink = (stage_t*)NULL;/**//*The last stage's next = NULL*/ //Terminate list  //36-37 The link member of the final stage is set to NULL to terminate the list, and the pipeline's tail is set to point at the final stage. The tail pointer allows pipe_result to easily find the final product of the pipeline, which is stored into the final stage.
	sttPipe->tail = sttNewStage; //Record the tail //37
	for (sttStage = sttPipe->head; sttStage->next != NULL; sttStage = sttStage->next) { //52-59 After all the stage data is initialized, pipe_create creates a thread for each stage. The extra "final stage" does not get a thread—the termination condition of the for loop is that the current stage's next link is not NULL, which means that it will not process the final stage.			//Create the threads for the pipe stages only after all the data is initialized(including all links). Note that the last stage doesn't get a thread, it's just a receptacle for the final pipeline value. At this point, proper cleanup on an error would take up more space than worthwhile in a "simple example," so instead of cancelling and detaching all the threads already created, plus the synchronization object and memory cleanup done for earlier errors, it will simply abort.
		intStatus = pthread_create(&sttStage->thread, NULL, pipe_stage/*1.2*/, (void*)sttStage); if (intStatus != 0) err_abort(intStatus, "Create pipe stage");
	} //59
	return 0;
}

int pipe_start(pipe_t* sttPipe, long lngValue) { //Part 5 shows pipe_start and pipe_result. The pipe_start function pushes an item of data into the beginning of the pipeline and then returns immediately without waiting for a result. The pipe_result function allows the caller to wait for the final result, whenever the result might be needed.		//External interface to start a pipeline by passing data to the first stage. The routine returns while the pipeline processes in parallel. Call the pipe_result return to collect the final stage values(note that the pipe will stall when each stage fills, until the result is collected).
	int intStatus;
	intStatus = pthread_mutex_lock(&sttPipe->mutex); if (intStatus != 0)	err_abort(intStatus, "Lock pipe mutex");
	sttPipe->active++;
	intStatus = pthread_mutex_unlock(&sttPipe->mutex);	if (intStatus != 0) err_abort(intStatus, "Unlock pipe mutex"); //	//19-22 The pipe_start function sends data to the first stage of the pipeline. The function increments a count of "active" items in the pipeline, which allows pipe_ result to detect that there are no more active items to collect, and to return immediately instead of blocking. You would not always want a pipeline to behave this way — it makes sense for this example because a single thread alternately "feeds" and "reads" the pipeline, and the application would hang forever if the user inadvertently reads one more item than had been fed.
	pipe_send/*2.2*/(sttPipe->head, lngValue);
	return 0; //22
}

int pipe_result(pipe_t* pipe, long *result) { //23-47 The pipe_result function first checks whether there is an active item in the pipeline. If not, it returns with a status of 0, after unlocking the pipeline mutex.			//Collect the result of the pipeline. Wait for a result if the pipeline hasn't produced one.
	stage_t* tail = pipe->tail;
	//ORIG unused: long value;
	int empty = 0;
	int intStatus;

	intStatus = pthread_mutex_lock(&pipe->mutex); if (intStatus != 0)	err_abort(intStatus, "Lock pipe mutex");
	if (pipe->active <= 0)
		empty = 1;
	else
		pipe->active--;
	intStatus = pthread_mutex_unlock(&pipe->mutex);	if (intStatus != 0) err_abort(intStatus, "Unlock pipe mutex");

	if (empty)
		return 0; //47

	pthread_mutex_lock(&tail->mutex); //48-55 If there is another item in the pipeline, pipe_result locks the tail(final) stage, and waits for it to receive data. It copies the data and then resets the stage so it can receive the next item of data. Remember that the final stage does not have a thread, and cannot reset itself.
	while (!tail->dataReady)
		pthread_cond_wait(&tail->condAvail, &tail->mutex);
	*result = tail->data;
	tail->dataReady = 0;
	pthread_cond_signal(&tail->condReady);
	pthread_mutex_unlock(&tail->mutex); //55

	return 1;
}

int main() { //Part 6 shows the main program that drives the pipeline. It creates a pipeline, and then loops reading lines from stdin. If the line is a single "=" character, it pulls a result from the pipeline and prints it. Otherwise, it converts the line to an integer value, which it feeds into the pipeline.			//The main program to "drive" the pipeline...
	const unsigned intStages = 10;
	pipe_t sttMyPipe;
	long lngValue, lngResult;
	char chrLine[128];
	pipe_create/*1.1*/(&sttMyPipe, intStages);
	printf("Enter integer values, or \"=\" for next result\n");
	while (1) {
		printf("Data> ");
		if (fgets(chrLine, sizeof(chrLine), stdin) == NULL) exit(0);
		if (strlen(chrLine) <= 1) continue;
		if (strlen(chrLine) <= 2 && chrLine[0] == '=') {
			if (pipe_result(&sttMyPipe, &lngResult))
				printf("Result is %ld\n", lngResult);
			else
				printf("Pipe is empty\n");
		} else {
			if (sscanf(chrLine, "%ld", &lngValue) < 1)
				fprintf(stderr, "Enter an integer lngValue\n");
			else
				pipe_start/*2.1*/(&sttMyPipe, lngValue);
		}
	}
}
