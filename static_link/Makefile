CC = gcc
OUTPUT_OPTIONS = -o $@


SOURCE = addvec.c multvec.c
OBJ = $(SOURCE:.c=.o)

LIB_PATH = -L.
LIB = -lvector

all: prog2

libvector.a: $(OBJ)
	ar rcs libvector.a $(OBJ)

prog2: libvector.a main2.o
	gcc -static -o prog2 main2.o $(LIB_PATH) $(LIB)

clean:
	rm libvector.a
	rm *.o
	rm prog2
