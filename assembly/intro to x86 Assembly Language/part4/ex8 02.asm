global _start
   
funcOrig:
    push ebp                ; The prologue: preservig the stack. At the very beginning of the function before altering the stack pointer register (ebp), store its value on the stack because it will be used to alter and restore the stack pointer. This lets the calling functions use ebp given the state it has been at before calling this function
    mov ebp, esp            ; Store the top of the stack stored in the stack pointer register (esp) in the base pointer register (ebp).    
    sub esp, 2              ; Allocate 2 bytes on the stack.

    mov [esp], byte 'H'
    mov [esp+1], byte 'i'
    
    mov eax, 4              ; sys_write system call
    mov ebx, 1              ; stdout file descriptor
    mov ecx, esp            ; bytes to write
    mov edx, 2              ; number of bytes to write
    int 0x80                ; perform system call
    
    mov esp, ebp            ; The epilogue. Restore esp from ebp. This deallocates the space allocated above and puts the stack to the state when the function was called, so that ret can be used below.    
    pop ebp                 ; At the very end of the function, restore the stack pointer register.
    ret
    
    
funcTest:  
    sub esp, 2              ; Allocate 2 bytes on the stack.
    mov [esp], byte 'H'
    mov [esp+1], byte 'i'
       
    mov eax, 4              ; sys_write system call
    mov ebx, 1              ; stdout file descriptor
    mov ecx, esp            ; bytes to write
    mov edx, 2              ; number of bytes to write
    int 0x80                ; perform system call
    
    add esp, 2              ; TEST Restore esp back to the state it was before allocating 2 bytes.
    ret

    
_start:
    call funcOrig
    call funcTest

    mov eax, 1
    mov ebx, 0
    int 0x80
