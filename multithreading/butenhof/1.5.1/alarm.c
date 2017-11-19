//#include "errors.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
    int seconds;
    char line[128];
    char message[64];
    while (1) {
        printf ("Alarm> ");
        if (fgets (line, sizeof (line), stdin) == NULL)
            exit (0);
        if (strlen (line) <= 1)
            continue;

        if (sscanf (line, "%d %64[^\n]", &seconds, message) < 2) //Parse input line into seconds (%d) and a message (%64[^\n]), consisting of up to 64 characters separated from the seconds by whitespace.
            fprintf (stderr, "Bad command\n");
        else {
            sleep (seconds);
            printf ("(%d) %s\n", seconds, message);
        }
    }
}


/*
//C library function - sscanf() @ https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int day, year;
   char weekday[20], month[20], dtm[100];

   strcpy( dtm, "Saturday March 25 1989" );
   sscanf( dtm, "%s %s %d  %d", weekday, month, &day, &year );

   printf("%s %d, %d = %s\n", month, day, year, weekday );

   return(0);
}
*/
