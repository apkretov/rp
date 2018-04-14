section .data
    strHelloWorld db "Hello, World!",10,0
    strWorld db "World?",10,0

section .text
    global _start


_start:
    mov rax, strHelloWorld  ; Place the string's 1s symbol's adress onto the stack to print it.
    call _print

    mov rax, strWorld       ; Repeat the operation again.
    call _print

    mov rax, 60             ; Exit.
    mov rdi, 0
    syscall

    
_print:                     ; input: rax as a pointer to a string.
    push rax                ; Store the string's 1s symbol's adress in the stack. rax will be used for other purposes now.
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

