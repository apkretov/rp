global _start

_start:
    sub esp, 4			; Allocate 4 bytes on the stack.
    mov [esp], byte 'H'		; Put "Hey!" onto the stack.
    mov [esp+1], byte 'e'
    mov [esp+2], byte 'y'
    mov [esp+3], byte '!'
    
    mov eax, 4    ; sys_write system call
    mov ebx, 1    ; stdout file descriptor
    mov ecx, esp  ; bytes to write. The stack pointer points to the first byte to print out from.
    mov edx, 4    ; number of bytes to write
    int 0x80      ; perform system call
    
    mov eax, 1    ; sys_exit system call
    mov ebx, 0    ; exit status is 0
    int 0x80
