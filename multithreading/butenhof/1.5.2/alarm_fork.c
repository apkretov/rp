#include <sys/types.h>
#include <wait.h>
//#include "errors.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	int status;
	char line[128];
	int seconds;
	pid_t pid;
	char message[64];
	while (1) {
		printf ("Alarm> " ) ;
		if (fgets (line, sizeof (line), stdin) == NULL)
			exit (0);
		if (strlen (line) <= 1)
			continue;

		if (sscanf (line, "%d %64[^\n]", &seconds, message) < 2) { //Parse input line into seconds (%d) and a message (%64[^\n]), consisting of up to 64 characters separated from the seconds by whitespace.
			fprintf (stderr, "Bad command\n");
		} else {
			pid = fork();
			if (pid == (pid_t)-1)
				/*ORIG errno_abort ("Fork");*/ printf("errno_abort ('Fork'))");
			if (pid == (pid_t)0) {
				sleep (seconds); // In the child, wait and then print a message
				printf ("(%d) %s\n", seconds, message);
				exit (0);
			} else {
				do { //In the parent, call waitpid() to collect children that have already terminated.
					pid = waitpid ((pid_t)-1, NULL, WNOHANG);
					if (pid == (pid_t)-1)
						/*ORIG errno_abort ("Wait for child");*/ printf("errno_abort('Wait for child')");
				} while (pid /*ORIG Zombie error: != */ == (pid_t)0);
			}
		}
	}
}
