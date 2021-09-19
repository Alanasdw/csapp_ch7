
CC = gcc
OUTPUT_OPTIONS = -o $@

SOURCE = target.c
OBJ = $(SOURCE:.c=.o)

all: inter

run: inter
	LD_PRELOAD="./mystdlib.so" ./inter

inter: $(OBJ) mystdlib.so
	$(CC) -o inter $(OBJ)

mystdlib.so: mystdlib.c
	$(CC) -DRUNTIME -D_GNU_SOURCE -shared -fpic -o mystdlib.so mystdlib.c -ldl

clean:
	rm mystdlib.so
	rm *.o
	rm inter
