CFLAGS=-Wall -O -Wuninitialized

HELLO=h1
OHELLO=h1.o greets.o

all:	$(HELLO)

$(HELLO):	$(OHELLO)
	cc -o$(HELLO) h1.o greets.o

h1.o:		greets.h
greets.o:	greets.h

clean:
	-rm h1
	-rm *.o
