section .bss
    digitSpace resb 100             ; Reserve a space for the digits of a number printed out .
    digitSpacePos resb 8            ; It keeps track how far in digitSpace we are. 8 bytes are enough for a 64 bit-number.

section .text
    global _start

_start:
    mov rax, 123                    ; Print this number.
    call _printRAX

    mov rax, digitSpace ;MINE
    call _printRAX ;MINE

    mov rax, digitSpacePos ;MINE
    call _printRAX ;MINE

    mov rcx, digitSpace ;MINE
    inc rcx ;MINE
    mov rax, rcx ;MINE
    call _printRAX; MINE

    mov rax, 60                     ; Exit.
    mov rdi, 0
    syscall


_printRAX:
    mov rcx, digitSpace             ; digitSpace will store the string to print out. We start at the beginning of digitSpace and increment the position below (inc rcx).
    mov rbx, 10                     ; Break down the number backwards, so put the end-line character (10) to the beginning of the digit string stored in rbx.
    mov [rcx], rbx ;MINE: [digitSpace], rbx
    ;MINE mov [digitSpace], 10 ;ERR: operation size not specified
    ;MINE mov digitSpace, 10 ;ERR: invalid combination of opcode and operands
    inc rcx                         ; Increment the position in digitSpace.
    mov [digitSpacePos], rcx        ; Store the position incremented.

_printRAXLoop:
    mov rdx, 0                      ; No rax-rdx numerator concatination. Only a 64-bit (unlike 128) numerator is goning to be divided, which currently is 123.
    mov rbx, 10
    div rbx                         ; 123 / 10 = 12, remainder 3. 12 is stored in rax, 3 is stored in rdx.

    push rax                        ; Store the quotient on the stack.
    add rdx, 48                     ; Convert remainder 3 to a character by adding ASCII code 48 (0 character).

    mov rcx, [digitSpacePos]        ; Unlike the initial 'mov rcx, digitSpace' above, which was actually the 1st position of the digitSpace byte series, rcx gets now the current position that digitSpacePos stores.
    mov [rcx], dl
    inc rcx
    mov [digitSpacePos], rcx

    pop rax
    cmp rax, 0
    jne _printRAXLoop

_printRAXLoop2:
    mov rcx, [digitSpacePos]

    mov rax, 1
    mov rdi, 1
    mov rsi, rcx ;MINE: mov rsi, [digitSpacePos] 
    mov rdx, 1
    syscall

    mov rcx, [digitSpacePos]
    dec rcx
    mov [digitSpacePos], rcx

    cmp rcx, digitSpace
    jge _printRAXLoop2

    ret
