IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o:	%.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@ #ORIG: $(CC) -c -o $@ $< $(CFLAGS)

hellomake:	$(OBJ)
	gcc $^ $(CFLAGS) $(LIBS) -o $@ #ORIG: gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY:	clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)