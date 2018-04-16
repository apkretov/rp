.set MAGIC, 0x1badb002			/* 'magic number' lets bootloader find the header */ /* Declare constants for the multiboot header. */  /* See all these at Bootstrap Assembly @ https://wiki.osdev.org/Bare_Bones#Bootstrap_Assembly */
/* ORIG .set FLAGS, (1<<0 | 1<<1) */
.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* this is the Multiboot 'flag' field */
.set CHECKSUM, -(MAGIC + FLAGS)	/* checksum of above, to prove we are multiboot */

.section .multiboot 			/* Declare a multiboot header that marks the program as a kernel. These are magic values that are documented in the multiboot standard. The bootloader will search for this signature in the first 8 KiB of the kernel file, aligned at a 32-bit boundary. The signature is in its own section so the header can be forced to be within the first 8 KiB of the kernel file. */
    .long MAGIC
    .long FLAGS
    .long CHECKSUM


.section .text
.extern kernelMain
.extern callConstructors
.global loader


loader:							/* The program entry point. */
    mov $kernel_stack, %esp 	/* Set the stack pointer to some pointer to some stack. That pointer is declared at the end of the file. */
    call callConstructors
    push %eax					/* Store on the stack the pointer to the multiboot structure with the RAM size etc. that the bootloader has retrtieved. 27:38 Write your own Operating System in 1 hour. */
    push %ebx					/* Store on the stack the magic number that the bootloader has put to ebx. 27:38 Write your own Operating System in 1 hour. */
    call kernelMain				/* The infinite loop in kernelMain is not supposed to end. But to ensure that the computer gets hung another infinite cli/hlt loop is arranged below. */


_stop:							/* The additional infinite loop. */
    cli							/* Disable interrupts */ /* CLI @ https://en.wikipedia.org/wiki/Interrupt_flag#CLI */
    hlt							/* Because the HLT instruction halts until an interrupt occurs, the combination of a CLI followed by a HLT is commonly used to intentionally hang the computer. */ /* CLI @ https://en.wikipedia.org/wiki/Interrupt_flag#CLI */
    jmp _stop


.section .bss
.space 2*1024*1024				/* # 2 MiB */
kernel_stack:					/* The position for the kernel stack. */
