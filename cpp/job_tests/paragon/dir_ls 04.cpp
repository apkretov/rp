//dirent_052.cpp //Developing Linux Utility like 'ls' in C. Omitting the files from output that begin with '.' @ https://www.go4expert.com/articles/developing-linux-utility-ls-c-t27426/
#ifdef WIN32 //In MSVS 2017, the following setting makes this inclusion unnecessary: Project Properties Menu -> Configuration Properties -> C/C++ -> Advanced -> Forced Include File: StdAfx.h %(ForcedIncludeFiles)
#include "stdafx.h"
#endif //WIN32
#include <stdio.h>
#include <stdlib.h> //EXIT_SUCCESS, EXIT_FAILURE.
#include <iostream> //TO DO: Remove it unless used.
using std::cout;
using std::endl;
//#include <stdlib.h>
//#include <sys/types.h> //TO DO: Document.
#ifndef WIN32 //TO DO: Comment this and remove the following comment: //C++ How to check the last modified time of a file @ https://stackoverflow.com/questions/40504281/c-how-to-check-the-last-modified-time-of-a-file
#include <dirent.h>
#else
#include "dirent.h"
#endif //WIN32
#include <sys/stat.h> //TO DO: Check if these are necessary //stat in fsize
//#include <string.h>
//#include <errno.h>
#include <time.h>

//off_t fsize(const char* const filename) { //How do you determine the size of a file in C? @ https://stackoverflow.com/questions/8236/how-do-you-determine-the-size-of-a-file-in-c
//    struct stat st;
//
//	 if (stat(filename, &st) == 0)
//        return st.st_size;
//    fprintf(stderr, "Cannot determine size of %s: %s\n", filename, strerror(errno)); //Print a message on error
//    
//	 return -1; //Returns -1 on error instead of 0, which would be ambiguous for an empty file. off_t is a signed type so this is possible.
//}
//
//int main(void) {
//	char *curr_dir = NULL;
//	DIR *dp = NULL;
//	struct dirent *dptr = NULL;
//	unsigned int count = 0;
//	off_t lngFileSize = 0;
//
//	curr_dir = ".";
//	if (NULL == curr_dir)	{
//		printf("\n ERROR : Could not get the directory\n");
//		return EXIT_FAILURE;
//	}
//
//	dp = opendir((const char*)curr_dir);
//	if (NULL == dp)	{
//		printf("\n ERROR : Could not open the directory\n");
//		return EXIT_FAILURE;
//	}
//
//	for (count = 0; NULL != (dptr = readdir(dp)); count++)	{ //TO DO: Print the column headers.
//		if (dptr->d_name[0] != '.') { // Check if the name of the file/folder begins with '.'. If yes, then do not display it.
//			lngFileSize = fsize(dptr->d_name);
//			if (lngFileSize >= 0)
//				cout << dptr->d_name << '\t' << lngFileSize << endl; //TO DO: Right allign the file sizes.
//			else
//				return EXIT_FAILURE;
//		}
//	}
//
//	return 0;
//}

int main(void) {
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	unsigned int count = 0;
	off_t lngFileSize = 0;
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

	while (dptr = readdir(dp)) { //Reading Directories in C++ @ http://www.cse.unt.edu/~donr/courses/4410/NOTES/readingDirectoriesInUnix.html
		if (dptr->d_name[0] != '.') { // Check if the name of the file/folder begins with '.'. If yes, then do not display it.
			cout << dptr->d_name;
			stat(dptr->d_name, &buff);
			cout << "  File size: " << buff.st_size;
			cout << "  Modification time: " << ctime(&buff.st_mtime);
		}
	}
	closedir(dp);

	return 0;
}