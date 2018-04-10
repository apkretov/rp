STDIN equ 0
STDOUT equ 1
STDERR equ 2

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

ASCII_0 equ 48

section .data
	digit db 0,10

section .text
	global _start

_printRAXDigit:
	add rax, ASCII_0

	mov [digit], al
	mov rax, SYS_WRITE
	mov rdi, STDOUT
	mov rsi, digit
	mov rdx, 2
	syscall

	ret


%macro printDigit 1
	mov rax, %1
	call _printRAXDigit
%endmacro


%macro exit 0
	mov rax, SYS_EXIT
	mov rdi, 0
	syscall
%endmacro


_start:
	printDigit 3
	printDigit 4

	exit
