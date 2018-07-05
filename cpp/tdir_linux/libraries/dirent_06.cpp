/*
#include <stdio.h> //14.2.4 Simple Program to List a Directory @ http://www.gnu.org/software/libc/manual/html_node/Simple-Directory-Lister.html#Simple-Directory-Lister
//ORIG #include <sys/types.h>
#include <dirent.h>

int main (void) {
	DIR *dp;
	struct dirent *ep;

	dp = opendir ("./");
	if (dp != NULL) {
		while (ep = readdir (dp))
			puts (ep->d_name);
		(void) closedir (dp);
	}
	else
		perror ("Couldn't open the directory");

	return 0;
}
//The order in which files appear in a directory tends to be fairly random. A more useful program would sort the entries (perhaps by alphabetizing them) before printing them; see Scanning Directory Content, and Array Sort Function.
*/
