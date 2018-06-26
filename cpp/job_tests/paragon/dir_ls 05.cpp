//dirent_052.cpp //Developing Linux Utility like 'ls' in C. Omitting the files from output that begin with '.' @ https://www.go4expert.com/articles/developing-linux-utility-ls-c-t27426/
#ifdef WIN32 //In MSVS 2017, the following setting makes this inclusion unnecessary: Project Properties Menu -> Configuration Properties -> C/C++ -> Advanced -> Forced Include File: StdAfx.h %(ForcedIncludeFiles)
#include "stdafx.h"
#endif //WIN32
#include <stdio.h>
#include <stdlib.h> //EXIT_SUCCESS, EXIT_FAILURE.
//OFF for gcc #include <iostream> //TO DO: Remove it unless used.
//OFF for gcc using std::cout;
//#include <stdlib.h>
//#include <sys/types.h> //TO DO: Document.
#ifndef WIN32 //TO DO: Comment this and remove the following comment: //C++ How to check the last modified time of a file @ https://stackoverflow.com/questions/40504281/c-how-to-check-the-last-modified-time-of-a-file
#include <dirent.h>
#else
#include "dirent.h" //TO DO: Include this header file to the source one.
#endif //WIN32
#include <sys/stat.h> //TO DO: Check if these are necessary //stat in fsize
//#include <string.h>
//#include <errno.h>
#include <time.h>

int main(void) {
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	//unsigned int count = 0;
	//off_t lngFileSize = 0;
	struct stat buff;

	curr_dir = ".";
	if (NULL == curr_dir) {
		printf("\n ERROR : Could not get the directory\n");
		return EXIT_FAILURE;
	}

	dp = opendir((const char*)curr_dir);
	if (NULL == dp) {
		printf("\n ERROR : Could not open the directory\n");
		return EXIT_FAILURE;
	}

	while ( (dptr = readdir(dp)) ) { //Reading Directories in C++ @ http://www.cse.unt.edu/~donr/courses/4410/NOTES/readingDirectoriesInUnix.html
		if (dptr->d_name[0] != '.') { // Check if the name of the file/folder begins with '.'. If yes, then do not display it.
			//cout << dptr->d_name;
			printf("%s", dptr->d_name);
			stat(dptr->d_name, &buff);
//			cout << "  File size: " << buff.st_size;
//			cout << "  Modification time: " << ctime(&buff.st_mtime);
			printf("\tFile size: %ld", buff.st_size);
			printf("\tModification time: %s", ctime(&buff.st_mtime));
		}
	}
	closedir(dp);
	return 0;
}
