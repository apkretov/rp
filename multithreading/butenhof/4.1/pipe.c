//The program shows the pieces of a simple pipeline program. Each thread in the pipeline increments its input value by 1 and passes it to the next thread. The main program reads a series of "command lines" from stdin. A command line is either a number, which is fed into the beginning of the pipeline, or the character "=," which causes the program to read the next result from the end of the pipeline and print it to stdout.

#include <pthread.h>
#include "errors.h" 3
//Internal structure describing a "stage" in the pipeline. One for each thread, plus a "result stage" where the final thread can stash the value.

typedef struct stage_tag { //9-17 Each stage of a pipeline is represented by a variable of type stage_t. stage_t contains a mutex to synchronize access to the stage. The avail condition variable is used to signal a stage that data is ready for it to process, and each stage signals its own ready condition variable when it is ready for new data. The data member is the data passed from the previous stage, thread is the thread operating this stage, and next is a pointer to the following stage.
	pthread_mutex_t mutex; /* Protect data */
	pthread_cond_t avail; /* Data available */
	pthread_cond_t ready; /* Ready for data */
	int data_ready; /* Data present */
	long data; /* Data to process */
	pthread_t thread; /* Thread for stage */
	struct stage_tag *next; /* Next stage */
} stage_t; //17

//External structure representing the entire pipeline.

23 typedef struct pipe_tag {

	24 pthread_mutex_t mutex; /* Mutex to protect pipe */

	25 stage_t *head; /* First stage */

	26 stage_t *tail; /* Final stage */

	27 int stages; /* Number of stages */

	28 int active; /* Active data elements */

	29 } pipe_t;

