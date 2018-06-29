/*
// dirent_052.cpp //Developing Linux Utility like 'ls' in C. Omitting the files from output that begin with '.' @ https://www.go4expert.com/articles/developing-linux-utility-ls-c-t27426/

#ifndef WIN32				// Linux, gcc. //TO DO: Comment this and remove the following comment: //C++ How to check the last modified time of a file @ https://stackoverflow.com/questions/40504281/c-how-to-check-the-last-modified-time-of-a-file
#include <dirent.h>
#else							// Windows, MSVS.
#include "stdafx.h"		// In MSVS 2017, this is unnecessary if %(ForcedIncludeFiles) includes StdAfx.h (Configuration Properties -> C/C++ -> Advanced -> Forced Include File).
#include "dirent.h"		// TO DO: Include this header file to the source one.
#endif						// WIN32

#include <stdio.h>
#include <stdlib.h>		// For EXIT_SUCCESS, EXIT_FAILURE constants.
#include <sys/types.h>	// TO DO: Document.
#include <sys/stat.h>	// For the stat structure. //TO DO: Check if these are necessary
#include <time.h>			// For the ctime function.

int main(void) {
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	struct stat buff;

	printf("dir_ls_01_dirent\n\n");
	curr_dir = ".";
	if (NULL == curr_dir) {
		printf("\n ERROR: Could not get the directory!\n");
		return EXIT_FAILURE;
	}

	dp = opendir((const char*)curr_dir);
	if (NULL == dp) {
		printf("\n ERROR: Could not open the directory!\n");
		return EXIT_FAILURE;
	}

	while ( (dptr = readdir(dp)) ) {		// TO DO: Sort entries. // TO DO: Print column headers aligned. //Reading Directories in C++ @ http://www.cse.unt.edu/~donr/courses/4410/NOTES/readingDirectoriesInUnix.html
		if (dptr->d_name[0] != '.') {		// Check if the name of the file/folder begins with '.'. If yes, then do not display it.
			printf("%s", dptr->d_name);	// TO DO: Align the print-outs.
			stat(dptr->d_name, &buff);
			printf("\tFile size: %ld", buff.st_size);
			printf("\tModification time: %s", ctime(&buff.st_mtime));	// TO DO: Print out in a shorter format.
		}
	}
	closedir(dp);
	return 0;
}
*/
