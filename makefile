all: a.out
a.out: Nossobuffer.c buffend.o arvbi.o
		gcc -Wall Nossobuffer.c buffend.o arvbi.o
buffend.o: buffend.c
		gcc -Wall -c buffend.c  
arvbi.o: arvbi.c
		gcc -Wall -c arvbi.c
order:
	rm *.o *~
clean:
	rm *.o *~ a.out

