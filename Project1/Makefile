CC= gcc
CFLAGS= -Wall -I.
DEPS = list.h
OBJ = list_test.o list.o 
ODIR=obj


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

list_test: list_test.o list.o 
	$(CC) -o list_test list_test.o list.o

.PHONY: clean

clean:
	rm *.o
