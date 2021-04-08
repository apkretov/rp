%include "linux64.inc"

section .data
    filename db "myfile.txt",0
    ;ORIG text db "Here's some text."
    text db "Here's some text.",10 ;MINE
    len	equ $-text ;MINE: Smallest x86 ELF Hello World @ http://timelessname.com/elfbin/
    fileDescriptor db "File descriptor: ",0 ;MINE
    cr db "",10,0 ;MINE

section .text
    global _start

_start:
    mov rax, SYS_OPEN
    mov rdi, filename
    mov rsi, O_CREAT + O_WRONLY
    mov rdx, 0644o
    syscall
    
    push rax ;Store the opened file descriptor on the stack.

    mov rdi, rax
    mov rax, SYS_WRITE
    mov rsi, text
    ;ORIG mov rdx, 17
    mov rdx, len ;MINE
    syscall

    print fileDescriptor ;MINE
    printVal [rsp] ;MINE Display the file descriptor stored on the stack.
    print cr ;MINE

    mov rax, SYS_CLOSE
    pop rdi
    syscall

    exit