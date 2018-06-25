/*
#include <stdio.h> //И для Win и для Lin можно использовать один код для показа содержимого директории: @ https://ru.stackoverflow.com/questions/503920/%D0%90%D0%BD%D0%B0%D0%BB%D0%BE%D0%B3-%D1%83%D1%82%D0%B8%D0%BB%D0%B8%D1%82%D1%8B-dir-c
#include <sys/types.h> //только для Lin
//#include <dirent.h>
#include "dirent.h"

int main() {
	 DIR *dir;
	 struct dirent *entry;

	 //dir = opendir("/");
	 //dir = opendir("~");
	 dir = opendir("/home/alex");
	 if (!dir) {
		  perror("diropen");
		  return 1;
	 };

	 while ( (entry = readdir(dir)) != NULL) {
		  printf("%s\n", entry->d_name);
	 };

	 closedir(dir);
	 return 0;
};
*/
