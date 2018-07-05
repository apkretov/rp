/*
#include <stdio.h> //Я думаю, ниже фрагмента можно использовать список всех файлов. @ http://qaru.site/questions/17239/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
#include <dirent.h>
//ORIG #include <sys/types.h>

static void list_dir(const char *path) {
	struct dirent *entry;
	DIR *dir = opendir(path);
	if (dir == NULL) {
		return;
	}

	while ((entry = readdir(dir)) != NULL) {
		printf("%s\n",entry->d_name);
	}

	closedir(dir);
}

int main() {
	list_dir("/home/alex/Downloads");
}
*/
