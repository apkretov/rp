/*
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> //NULL //EXIT_SUCCESS, EXIT_FAILURE @ https://en.cppreference.com/w/c/program/EXIT_status

int main() {
	DIR *dir; //В небольших и простых задачах я не использую boost, я использую dirent.h, который также доступен для окон: @ http://qaru.site/questions/17239/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
	struct dirent *ent;
	//if ((dir = opendir ("c:\\src\\")) != NULL) {
	if ((dir = opendir ("/home/alex/Downloads")) != NULL) {
		//print all the files and directories within directory
		while ((ent = readdir (dir)) != NULL) {
			printf ("%s\n", ent->d_name);
		}
		closedir (dir);
	} else {
		//could not open directory
		perror ("");
		return EXIT_FAILURE;
	}
}
*/
