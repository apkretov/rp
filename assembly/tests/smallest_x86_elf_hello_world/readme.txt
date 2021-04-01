gcc - How to make compiler generate a "elf32-x86-64" format object file? (elf64 to elf32) 
@ https://stackoverflow.com/questions/58654288/how-to-make-compiler-generate-a-elf32-x86-64-format-object-file

1) Instead of:
gcc -o chello chello.c
run this to compile a 32-bit version:
gcc -mx32 -o chello chello.c
Otherwise a 64-bit version will be compiled as usually:
gcc -o chello chello.c

2) The original is wrong: hello_orig_wrong.asm
Compile mine edited: hello.asm

3) Instead of:
nasm -f elf hello.asm 
run:
nasm -f elf64 hello.asm
