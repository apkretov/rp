%include "linux64.inc"

;ORIG section .data
section .rodata ;MINE
    newline db 10,0
    
section .text
    global _start
    
_start:
    pop rax
    printVal rax
    print newline
    exit