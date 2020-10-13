CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
OBJECTS = test.o hexFunctions.o typeCode.o df_ca_icao_decoder.o tc_data_decoder.o parity_functions.o dataFunctions.o positionFunctions.o

.PHONY: all
all: test

test.o: test.c
	$(CC) $(CFLAGS) -O3 -c test.c

hexFunctions.o: hexFunctions.c
	$(CC) $(CFLAGS) -O3 -c hexFunctions.c

typeCode.o: typeCode.c
	$(CC) $(CFLAGS) -O3 -c typeCode.c

df_ca_icao_decoder: df_ca_icao_decoder.c
	$(CC) $(CFLAGS) -O3 -c df_ca_icao_decoder.c

tc_data_decoder: tc_data_decoder.c
	$(CC) $(CFLAGS) -O3 -c tc_data_decoder.c

parity_functions: parity_functions.c
	$(CC) $(CFLAGS) -O3 -c parity_functions.c

dataFunctions: dataFunctions.c
	$(CC) $(CFLAGS) -O3 -c dataFunctions.c

positionFunctions: positionFunctions.c
	$(CC) $(CFLAGS) -O3 -c positionFunctions.c

test: $(OBJECTS)
	$(CC) -o test $(OBJECTS)

.PHONY: clean
clean:
	rm -f $(OBJECTS) test