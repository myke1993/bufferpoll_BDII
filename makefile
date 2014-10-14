all: a.out
a.out: main.c buffend.o
		gcc -Wall main.c buffend.o
buffend.o: buffend.c
		gcc -Wall -c buffend.c
order:
	rm *.o *~
clean:
	rm *.o *~ a.out

