#include <stddef.h> //Define NULL.
#include <stdio.h>
#include <stdbool.h> //Define bool.
#include <dlfcn.h>

void (*hello_message)(const char* const);

bool init_library() {
	void* hndHello_message = dlopen("./libHello.so", RTLD_LAZY);
	if (hndHello_message == NULL) return false;
	
	hello_message = (void(*)(const char* const))dlsym(hndHello_message, "hello_message");
	if (hello_message == NULL) return false;

	return true;
}

int main() {
	if (init_library()) hello_message("Alexander");
	else printf("A liblray has not been loaded.");
	return 0;
}
