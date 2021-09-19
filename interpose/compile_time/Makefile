
CC = gcc
OUTPUT_OPTIONS = -o $@

all: inter

inter: mystdlib.c target.c
	$(CC) -DCOMPILETIME -c mystdlib.c
	$(CC) -I. -o inter target.c mystdlib.o

clean:
	rm mystdlib.o
	rm inter
