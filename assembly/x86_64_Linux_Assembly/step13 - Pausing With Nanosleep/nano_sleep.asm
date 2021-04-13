;ORIG section .data
section .rodata ;MINE
    delay dq 5, 500000000

section .text
    global _start

_start:
    mov rax, 35
    mov rdi, delay
    mov rsi, 0
    syscall

    mov rax, 60
    mov rdi, 0
    syscall
