
CC = gcc
OUTPUT_OPTIONS = -o $@

SOURCE = mystdlib.c target.c
OBJ = $(SOURCE:.c=.o)

inter: $(OBJ)
	$(CC) -Wl,--wrap,malloc -Wl,--wrap,free -o inter $(OBJ)

mystdlib.o: mystdlib.c
	$(CC) -DLINKTIME -c -o mystdlib.o mystdlib.c

clean:
	rm *.o
	rm inter
