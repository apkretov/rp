section .data
    text db "Hello, World!",10,0
    textMine db "World?",10,0

section .text
    global _start


_start:
    mov rax, text  ; Place the string's 1s symbol's address onto the stack to print it.
    call _print

    mov rax, textMine       ; Repeat the operation again.
    call _print

    mov rax, 60             ; Exit.
    mov rdi, 0
    syscall

    
_print:                     ; Input: rax as a pointer to a string. Output: print string at rax.
    push rax                ; Store the string's 1s symbol's address in the stack. rax will be used for other purposes now.
    mov rbx, 0
_printLoop:
    inc rax                 ; Move to the next symbol.
    inc rbx                 ; The length count is going to be stored in rbx. Increment it.

    mov cl, [rax]           ; Check if the current symbol (stored in the lowest byte) is 0.
    cmp cl, 0
    jne _printLoop          ; Loop, unless it is 0.

    mov rax, 1              ; Output the string.
    mov rdi, 1
    pop rsi
    mov rdx, rbx            ; The length is taken from rbx.
    syscall
    
    ret

