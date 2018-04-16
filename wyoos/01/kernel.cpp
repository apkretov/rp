void printf(char* str) {
	static unsigned short* shrVideoMemory = (unsigned short*)0xb8000; // The address the video card displays characters from.
	const unsigned short shrHighMask = 0xFF00; // bit mask to keep high 4 bits (hex for 1111 0000) // 3.8a � Bit flags and bit masks @ http://www.learncpp.com/cpp-tutorial/3-8a-bit-flags-and-bit-masks/
	for(int i = 0; str[i] != '\0'; ++i) {
		//ORIG shrVideoMemory[i] = (shrVideoMemory[i] & 0xFF00) | str[i];
		shrVideoMemory[i] = (shrVideoMemory[i] & shrHighMask) | str[i];
	}
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
	for(constructor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}

// ORIG extern "C" void kernelMain(const void* multiboot_structure, unsigned int /* multiboot_magic */) { // We can call the function however we want. We will call it kernelMain.
extern "C" void kernelMain(const void* multiboot_structure, unsigned int multiboot_magic) { // We can call the function however we want. We will call it kernelMain. // Accept multiboot_structure and multiboot_magic that have been put onto the stack in loader.s (29:21 Write your own Operating System in 1 hour).
	printf("Hello from MyOS!");
	while(1); // Stay in an infinite loop.
}
