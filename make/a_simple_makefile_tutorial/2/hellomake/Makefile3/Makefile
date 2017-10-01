#ORIG CC=gcc
#ORIG CFLAGS=-I.
CFLAGS = -I. -c
DEPS = hellomake.h

%.o:	%.c $(DEPS)
#ORIG	$(CC) -c -o $@ $< $(CFLAGS)
	$(CC) $< $(CFLAGS) -o $@ #TEST

hellomake:	hellomake.o hellofunc.o 
	gcc -o hellomake hellomake.o hellofunc.o -I.
