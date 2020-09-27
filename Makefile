CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
OBJECTS = test.o hexFunctions.o typeCode.o

.PHONY: all
all: test

test.o: test.c
	$(CC) $(CFLAGS) -O3 -c test.c

hexFunctions.o: hexFunctions.c
	$(CC) $(CFLAGS) -O3 -c hexFunctions.c

typeCode.o: typeCode.c
	$(CC) $(CFLAGS) -O3 -c typeCode.c

test: $(OBJECTS)
	$(CC) -o test $(OBJECTS)

.PHONY: clean
clean:
	rm -f $(OBJECTS) test