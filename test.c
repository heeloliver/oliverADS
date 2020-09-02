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
	int temp;
	int df;
	int ca;
	int icao;
	int data;
	int tc;
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

	hexToLong = strtol(hexProperlyFormatted, NULL, 0);
	printf("hexToInt: %ld\n", hexToLong);
	
	for (int i = 0; i < DFCHUNKLENGTH; i++)
	{
		dfChunk[i] = hex[i];
		dfChunk[i+1] = '\0';
	}
	temp = atoi(dfChunk);
	printf("dfChunk: %s\n", dfChunk);
	printf("temp: %d\n", temp);
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

	printf("hex:  %s\ndf:   %s\nca:   %s\nicao: %s\n", hex, dfChunk, caChunk, icaoChunk);
}






