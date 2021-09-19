CC = gcc
OUTPUT_OPTIONS = -o $@


SOURCE = addvec.c multvec.c
OBJ = $(SOURCE:.c=.o)

all: prog21

libvector.so: $(SOURCE)
	$(CC) -shared -fpic -o libvector.so $(SOURCE)

prog21: libvector.so main2.c
	$(CC) -o prog21 main2.c ./libvector.so

clean:
	rm libvector.so
	rm prog21
