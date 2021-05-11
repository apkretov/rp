.data
num:
    .long 0x12345678

.text

.globl main
.type main, @function
main:
    movl (num), %eax
