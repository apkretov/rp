#ORIG CC=gcc
CFLAGS = -I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

%.o:	%.c $(DEPS)
	#ORIG $(CC) -c -o $@ $< $(CFLAGS)
	$(CC) $< -c $(CFLAGS) -o $@

hellomake:	$(OBJ)
	gcc $^ $(CFLAGS) -o $@
	#TEST gcc $(OBJ) $(CFLAGS) -o $@
