#ORIG CC=gcc
CFLAGS = -I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

%.o:	%.c $(DEPS)
	$(CC) $< -c $(CFLAGS) -o $@ #ORIG: $(CC) -c -o $@ $< $(CFLAGS)

hellomake:	$(OBJ)
	gcc $^ $(CFLAGS) -o $@ #TEST: gcc $(OBJ) $(CFLAGS) -o $@
