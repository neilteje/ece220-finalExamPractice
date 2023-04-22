CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror -lm -lc

paths: tree.c problem2.c tree.h
	${CC} ${CFLAGS} tree.c problem2.c -o problem2

.PHONY: clean
clean:
	rm -f problem2

