CC = gcc
OUTPUT_OPTIONS = -o $@


SOURCE = addvec.c multvec.c
OBJ = $(SOURCE:.c=.o)

all: libvector.so prog2r

libvector.so: $(SOURCE)
	$(CC) -shared -fpic -o libvector.so $(SOURCE)

prog2r: main2.c
	gcc -rdynamic -o prog2r main2.c -ldl

clean:
	rm libvector.so
	rm prog2r
