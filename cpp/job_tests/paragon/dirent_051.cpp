/*
#include <stdio.h> //Developing Linux Utility like 'ls' in C. The code. @ https://www.go4expert.com/articles/developing-linux-utility-ls-c-t27426/
#include <stdlib.h>
//ORIG #include <sys/types.h>
#include <dirent.h>

int main(void) {
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	unsigned int count = 0;

	curr_dir = getenv("PWD"); // Get the value of environment variable PWD
	if(NULL == curr_dir)	{
		printf("\n ERROR : Could not get the working directory\n");
		return -1;
	}

	dp = opendir((const char*)curr_dir); // Open the current directory
	if(NULL == dp)	{
		printf("\n ERROR : Could not open the working directory\n");
		return -1;
	}

	printf("\n");
	for(count = 0; NULL != (dptr = readdir(dp)); count++)	// Go through and display all the names (files or folders) contained in the directory.
		printf("%s  ",dptr->d_name);
	printf("\n%u\n", count);

	return 0;
}
*/
