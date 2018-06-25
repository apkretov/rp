/*
#include <stdio.h> //Developing Linux Utility like 'ls' in C. Omitting the files from output that begin with '.' @ https://www.go4expert.com/articles/developing-linux-utility-ls-c-t27426/
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(void) {
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	unsigned int count = 0;

	curr_dir = getenv("PWD");
	if(NULL == curr_dir)	{
		printf("\n ERROR : Could not get the working directory\n");
		return -1;
	}

	dp = opendir((const char*)curr_dir);
	if(NULL == dp)	{
		printf("\n ERROR : Could not open the working directory\n");
		return -1;
	}

	printf("\n");
	for(count = 0; NULL != (dptr = readdir(dp)); count++)	{
		if(dptr->d_name[0] != '.') // Check if the name of the file/folder begins with '.'. If yes, then do not display it.
			printf("%s  ",dptr->d_name);
	}
	printf("\n");

	return 0;
}
*/
