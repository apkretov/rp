%include "linux64.inc"

section .data
    strNewline db 10,0
    
section .text
    global _start
    
_start:
    pop rax
    printVal rax
    print strNewline
    exit