#include <stdio.h>
#include <string.h>
#define DFLENGTH 5
#define CALENGTH 3
#define ICAOLENGTH 24
#define DATALENGTH 56
#define PILENGTH 24 

int main() {
	char* hex = "8D4840D6202CC371C32CE0576098";
	char DF[DFLENGTH + 1];
	char CA[CALENGTH + 1];
	char* ICAO;
	char* DATA;
	char* TC;
	char* PI;

	//DF = hex & 0x1f;
	//I don't think bitmasking works here because the hex string is too large to
	//covert to a number (like crazy big)...maybe just make a small chunk of the hex
	//into an int, and then mask? But at that point, I may as well do what I'm doing here
	
	for (int i = 0; i < DFLENGTH + 1; i++)
	{
		DF[i] = hex[i];
		printf("%c %c\n", hex[i], DF[i]);
	}
	printf("%d\n", DFLENGTH);
	printf("%lu\n", strlen(DF));
	printf("hex: %s\n df: %s", hex, DF);
}