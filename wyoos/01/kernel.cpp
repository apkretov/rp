void printf(char* str) {
	static unsigned short* VideoMemory = (unsigned short*)0xb8000;

	for(int i = 0; str[i] != '\0'; ++i)
		VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
	for(constructor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}

//ORIG extern "C" void kernelMain(const void* multiboot_structure, unsigned int /*multiboot_magic*/) { //We can call the function however we want. We will call it kernelMain.
extern "C" void kernelMain(const void* multiboot_structure, unsigned int multiboot_magic) { //We can call the function however we want. We will call it kernelMain. //Accept multiboot_structure and multiboot_magic that have been put onto the stack in loader.s (29:21 Write your own Operating System in 1 hour).
	printf("Hello World! --- http://www.AlgorithMan.de");
	while(1); //Stay in an infinite loop.
}
