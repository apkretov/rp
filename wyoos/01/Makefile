# sudo apt-get install g++ binutils libc6-dev-i386

PARAMS_GCC = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore # No glibc, no exception handling, no leading underscore in the section names (e.g. kernelMain vs. _kernelMain) etc. 39:39 Write your own Operating System in 1 hour.
PARAMS_ASM = --32
PARAMS_LD = -melf_i386

objects = loader.o kernel.o



%.o: %.cpp
	gcc $(PARAMS_GCC) -c -o $@ $<

%.o: %.s
	as $(PARAMS_ASM) -o $@ $<

mykernel.bin: linker.ld $(objects)
	ld $(PARAMS_LD) -T $< -o $@ $(objects)

install: mykernel.bin
		sudo cp $< /boot/mykernel.bin