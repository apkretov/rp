global _start

funcDownloaded:
    push ebp
    mov ebp, esp
    
    sub esp, 2
    mov [esp], byte 'H'
    mov [esp+1], byte 'i'
    
    mov eax, 4    ; sys_write system call
    mov ebx, 1    ; stdout file descriptor
    mov ecx, esp  ; bytes to write
    mov edx, 2    ; number of bytes to write
    int 0x80      ; perform system call
    
    mov esp, ebp
    pop ebp
    ret

    
funcVideo:
    mov ebp, esp            ; Store the top of the stack stored in the stack pointer register (esp) in the base pointer register (ebp).
    
    sub esp, 2              ; Allocate 2 bytes on the stack.
    mov [esp], byte 'H'
    mov [esp+1], byte 'i'
    
    mov eax, 4              ; sys_write system call
    mov ebx, 1              ; stdout file descriptor
    mov ecx, esp            ; bytes to write
    mov edx, 2              ; number of bytes to write
    int 0x80                ; perform system call
    
    mov esp, ebp            ; Restore esp from ebp. This deallocates the space allocated above and puts the stack to the state when the function was called, so that ret can be used below.
    ret
    
    
_start:
    ;call funcDownloaded
    call funcVideo

    mov eax, 1
    mov ebx, 0
    int 0x80
