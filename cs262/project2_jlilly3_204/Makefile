CFLAGS=-Wall -g

RadixSort: link.o
	gcc -o RadixSort link.o radix_sort.c $(CFLAGS)

link.o: link.c link.h
	gcc $(CFLAGS) -c link.c

clean:
	rm -f RadixSort *.o
