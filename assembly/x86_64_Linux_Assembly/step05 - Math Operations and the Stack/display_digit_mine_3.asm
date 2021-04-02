section .data
	;ORIG digit db 0, 10
	;digit db "00000000", 10 ;MINE
	digit db "0000000", 10 ;MINE
	len	equ $-digit			;MINE: Smallest x86 ELF Hello World @ http://timelessname.com/elfbin/

section .text
	global _start

_printRAXDigit:
	add rax, 48 			;Add zero to rax. ASCII 48 is zero.
	;ORIG mov [digit], al 	;Move the lowes 8 bits of rax (i.e. 1 byte or a char) to the digit adress.
	mov [digit], rax ;MINE

	mov rax, 1
	mov rdi, 1
	mov rsi, digit
	;ORIG mov rdx, 2
	mov rdx, len ;MINE
	syscall

	ret


_start:
	mov rax, 0 ;MINE
	call _printRAXDigit 	;Print 0.

	mov rax, 7 				;Print 7.
	call _printRAXDigit

	mov rax, 60 			;Exit.
	mov rdi, 0
	syscall
