all:	exe  

exe:	lib main.c
	gcc main.c -fPIC -ldl -o hello

lib:	hello.h hello.c
	gcc hello.c -shared -fPIC -o libHello.so

clean:	
	-rm hello libHello.so 2>/dev/null
