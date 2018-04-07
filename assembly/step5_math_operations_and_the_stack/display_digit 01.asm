section .data
	chrDigit db 0,10

section .text
	global _start

_printRAXDigit:
	add rax, 48 			;Add zero to rax. ASCII 48 is zero.
	mov [chrDigit], al 		;Move the lowes 8 bits of rax (i.e. 1 byte or a char) to the chrDigit adress.

	mov rax, 1
	mov rdi, 1
	mov rsi, chrDigit
	mov rdx, 2
	syscall

	ret


_start:
	jmp _testingMath		;Jump to the math tests because they will raise an error, if are executed together with the code below.

	call _printRAXDigit 	;Print 0.

	mov rax, 7 				;Print 7.
	call _printRAXDigit
	jmp _exit				;Jump to the exit because the code below raises an error.

_testingMath:				;Testing math.
	mov rax, 6 				;Test 6 / 2 = 3.
	mov rbx, 2
	div rbx
	call _printRAXDigit 	;Output 3.

	mov rax, 1				;Test 1 + 4 = 5.
	add rax, 4
	call _printRAXDigit 	;Output 5.

_exit:
	mov rax, 60 			;Exit.
	mov rdi, 0
	syscall
