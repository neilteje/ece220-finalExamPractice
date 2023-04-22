CC=g++
CFLAGS=-g -Wall

.PHONY: convert
convert: convert.o tree.o queue.o
	$(CC) $(CFLAGS) convert.o tree.o queue.o -o convert

convert.o:
	$(CC) $(CLFAGS) -c convert.c

tree.o:
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f tree.o convert.o convert
