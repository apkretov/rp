# W/o macros.
#exe:	factorial.c  functions.h  hello.c  main.c
#	gcc factorial.c  hello.c  main.c -o hello

# Example 1.
hello:	main.c hello.c factorial.c
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

# Example 2 does not work because $@.c is only hello.c. Though there are more dependents.
#hello:	main.c hello.c factorial.c
#	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@

# Example 3. It worked but I suspended studying this tutorial because I did not understand it clearly.
.cpp.o:
	$(CC) $(CFLAGS) -c $<
