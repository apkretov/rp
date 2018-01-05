1 #include <pthread.h>

2 #include "errors.h" 3

4 /*

5 * Define a structure, with a mutex and condition variable.

6 */

7 typedef struct my_struct_tag {

8 pthread_mutex_t mutex; /* Protects access to value */

9 pthread_cond_t cond; /* Signals change to value */

10 int value; /* Access protected by mutex */

11 } my_struct_t;

12

13 int main (int argc, char *argv[])

14 {

15 my_struct_t *data;

16 int status;

17

18 data = malloc (sizeof (my_struct_t));

19 if (data == NULL)

20 	errno_abort ("Allocate structure");

21 status = pthread_mutex_init (&data->mutex, NULL);

22 if (status != 0)

23 	err_abort (status, "Init mutex");

24 status = pthread_cond_init (&data->cond, NULL);

25 if (status != 0)

26 err_abort (status, "Init condition");

27 status = pthread_cond_destroy (&data->cond);

28 if (status != 0)

29 	err_abort (status, "Destroy condition");

30 status = pthread_mutex_destroy (&data->mutex);

31 if (status != 0)

32 	err_abort (status, "Destroy mutex");

33 (void)free (data);

34 return status;

35 }
