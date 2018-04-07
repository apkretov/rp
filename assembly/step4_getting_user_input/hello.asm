section .data
	strWhatName db "What is your name? "
	strHello db "Hello, "

section .bss
strName resb 16

section .text
	global _start

_printWhatName:
	mov rax, 1
	mov rdi, 1
	mov rsi, strWhatName
	mov rdx, 19
	syscall
	ret

_getName:
	mov rax, 0
	mov rdi, 0
	mov rsi, strName
	mov rdx, 16
	syscall
	ret

_printHello:
	mov rax, 1
	mov rdi, 1
	mov rsi, strHello
	mov rdx, 7
	syscall
	ret

_printName:
	mov rax, 1
	mov rdi, 1
	mov rsi, strName
	mov rdx, 16
	syscall
	ret

_start:
	call _printWhatName
	call _getName
	call _printHello
	call _printName
	mov rax, 60
	mov rdi, 0
	syscall
