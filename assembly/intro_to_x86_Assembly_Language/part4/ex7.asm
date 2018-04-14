global _start

func1:
    mov ebx, 42
    pop eax     ; Pop the return location off the stack into eax that call pushed onto the stack.
    jmp eax     ; Jump to the location stored in eax, which is immediately after call.

func2:
    mov ebx, 42
    ret         ; Pop the return location off the stack that call pushed onto the stack and jump to that location, which is immediately after call.
    
_start:
    call func1  ; Put the location of the next instruction below (mov eax, 1) onto the stack. Jump to the location labled func1.
    ;call func2
    mov eax, 1  ; ebx is not set here. It is going to be done so in func.
    int 0x80