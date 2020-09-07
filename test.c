#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DFCHUNKLENGTH 2
#define CALENGTH 3
#define ICAOLENGTH 24
#define DATALENGTH 56
#define PILENGTH 24 

int main() {
	char* hex = "8D4840D6202CC371C32CE0576098";
	int hexLength = strlen(hex);
	char hexProperlyFormatted[hexLength + 3];
	char dfChunk[DFCHUNKLENGTH + 1];
	char caChunk[CALENGTH + 1];
	char icaoChunk[ICAOLENGTH + 1];
	char* dataChunk;
	char* tcChunk;
	char* piChunk;
	long hexToLong;
	long df;
	long ca;
	long icao;
	long data;
	long tc;
	int pi;

	printf("hex length: %d\n", hexLength);
	hexProperlyFormatted[0] = '0';
	hexProperlyFormatted[1] = 'x';
	for (int i = 2; i < hexLength + 2; i++)
	{
		hexProperlyFormatted[i] = hex[i-2];
	}
	printf("hexProperlyFormatted: %s\n", hexProperlyFormatted);

	//need to break into chunks, way too long to put into one int or long :)
	char chunk1[9];
	long chunk1Long;
	for (int i = 0; i < 8; i++)
	{
		chunk1[i] = hex[i];
		chunk1[i+1] = '\0';
	}
	chunk1Long = strtol(chunk1, NULL, 16);
	printf("chunk1: %s\n", chunk1);
	printf("chunk1Long: %ld\n", chunk1Long);


	df = chunk1Long & (long)0xf8000000;
	df = df >> 27;
	printf("df: %ld\n", df);

	ca = chunk1Long & (long)0x7000000;
	ca = ca >> 24;
	printf("ca: %ld\n", ca);

	icao = chunk1Long & (long)0xffffff;
	printf("icao: %ld\n", icao);

	char chunk2[15];
	long chunk2Long;
	for (int i = 0; i < 14; i++)
	{
		chunk2[i] = hex[i + 8];
		chunk2[i+1] = '\0';
	}
	chunk2Long = strtol(chunk2, NULL, 16);
	printf("chunk2: %s\n", chunk2);
	printf("chunk2Long: %ld\n", chunk2Long);

	tc = chunk2Long & (long)0xF8000000000000;
	tc = tc >> 51;
	printf("tc: %ld\n", tc);

	data = chunk2Long;
	printf("data: %ld\n", chunk2Long);

	char chunk3[25];
	long chunk3Long;
	for (int i = 0; i < 24; i++)
	{
		chunk3[i] = hex[i + 22];
		chunk3[i+1] = '\0';
	}
	chunk3Long = strtol(chunk3, NULL, 16);
	printf("chunk3: %s\n", chunk3);
	printf("chunk3Long: %ld\n", chunk3Long);

	/**
	for (int i = 0; i < CALENGTH; i++)
	{
		CA[i] = hex[i + DFLENGTH];
		CA[i+1] = '\0';
	}
	for (int i = 0; i < ICAOLENGTH; i++)
	{
		ICAO[i] = hex[i + DFLENGTH];
		ICAO[i+1] = '\0';
	}**/
}






