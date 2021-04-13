%include "linux64.inc"

;ORIG section .data
section .rodata ;MINE
    fileDescriptor db "File descriptor: ",0 ;MINE The order matters: if this line is placed the last within the .rodata section it gets printed by its own! I do not know why...
    filename db "myfile.txt",0
    len equ 17 ;MINE
    cr db "",10 ;MINE

section .bss
    ;ORIG text resb 18 ; One more byte in addition to the file length for the zero terminating symbol.
    text resb len + 1 ;MINE

section .text
    global _start
_start:
    mov rax, SYS_OPEN
    mov rdi, filename
    mov rsi, O_RDONLY
    mov rdx, 0 ; MINE: Why is the file permission 0 but not something like 0644o? ORIG: It does not matter if we are only reading the file. 
    syscall
    
    push rax
    mov rdi, rax
    mov rax, SYS_READ
    mov rsi, text
    ;ORIG mov rdx, 17
    mov rdx, len ;MINE
    syscall

    print fileDescriptor ;MINE
    printVal [rsp] ;MINE
    print cr ;MINE

    mov rax, SYS_CLOSE
    pop rdi
    syscall

    print text
    print cr ;MINE
    exit