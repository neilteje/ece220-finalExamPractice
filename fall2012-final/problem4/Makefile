CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror -lm -lc

problem4: problem4.c polygon.c
	${CC} ${CFLAGS} polygon.c problem4.c -o problem4

.PHONY: clean
clean:
	rm -f problem4
