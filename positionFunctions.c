// positionFunctions.c
// includes code to help decode location messages
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif


// Returns number of longitude zones. Return int is constrainted between [1, 59].
int NL(int latitude)
{
	if (latitude == 0) return 59;
	else if (latitude == 87) return 2;
	else if (latitude == (-87)) return 2;
	else if (latitude > 87) return 1;
	else if (latitude < (-87)) return 1;
	else 
	{
		double a = (1 - cos(M_PI/(2*NZ)));
		double c = (M_PI/180)*latitude;
		double b = cos(c)*cos(c);

		double d = acos(1-(a/b));

		int result = floor((2*M_PI)/d);

		return result;
	}
}

int latIndex(int latCPREven, int latCPROdd)
{
	int j;

	j = floor(59 * latCPREven - 60 * latCPROdd + 0.5);

	return j;
}

long returnCPRLat(char* hex)
{
	char dataChunk[15];

	for (int i = 0; i < 14; i++)
	{
		dataChunk[i] = hex[i + 8];
		dataChunk[i + 1] = '\0';
	}


	long dataChunkLong = strtol(dataChunk, NULL, 16);
	long bitsLong = dataChunkLong & (long)0x3FFFE0000;
	bitsLong = bitsLong >> 17;


	return bitsLong;
}

long returnCPRLon(char* hex)
{
	char dataChunk[15];

	for (int i = 0; i < 14; i++)
	{
		dataChunk[i] = hex[i + 8];
		dataChunk[i + 1] = '\0';
	}

	printf("data: %s\n", dataChunk);

	long dataChunkLong = strtol(dataChunk, NULL, 16);
	long bitsLong = dataChunkLong & (long)0x1FFFF;

	return bitsLong;
}

int returnOddBit(char* hex)
{
	char chunk[15];

	// Gets the chunk we want.
	for (int i = 0; i < 14; i++)
	{
		chunk[i] = hex[i + 8];
		chunk[i+1] = '\0';
	}

	long chunkLong = strtol(chunk, NULL, 16);
	long bitLong = chunkLong & (long)0x400000000;
	bitLong = bitLong >> 34;

	return (int)bitLong;
}

double returnCoordinateDecimal(long coord)
{
	double i = (double)coord / 131072.0; 
	return (i);
}

int returnLatIndex(long latCPREven, long latCPROdd)
{
	int j;

	j = floor((59 * returnCoordinateDecimal(latCPREven)) - (60 * returnCoordinateDecimal(latCPROdd)) + 0.5);

	return j;
}


//double long returnLatitude(int j, long latCPREven, long latCPROdd)
double long returnLatitude(int j, long latCPREven)
{
	double dLatEven = (360 / 60);
	//double dLatOdd  = (360 / 59);

	double long latEven = dLatEven * ((j % 60) + returnCoordinateDecimal(latCPREven));
	printf("j: %i, mod: %i\n", j, (j % 60));
	//double long latOdd  = dLatOdd  * ((59 % j) + returnCoordinateDecimal(latCPROdd));

	if (latEven >= 270)
	{
		latEven = latEven - 360;
	}

	/*
	if (latOdd >= 270)
	{
		latOdd = latOdd - 360;
	}*/

	//double long lat;

	//TODO: encorporate time stamp
	return latEven;
}

double long returnLongitude(long latEven, long longCPREven, long longCPROdd)
{
	int ni = 0;
	int ni1 = NL(latEven);
	if (ni >= 1) ni = ni1;
	else ni = 1;

	long dLon = 360/ni;

	int m = floor((longCPREven * (NL(latEven) - 1)) - (longCPROdd * NL(latEven)) + 0.5);

	double long longitude = dLon * ((ni % m) + longCPREven);

	return longitude;
}

// Returns if frame is odd. Needs input of entire message in hex.
int isOddFrame(char* hex)
{
	int bit = returnOddBit(hex);
	
	if (bit == 0) 
	{
		return 0;
	}
	else if (bit == 1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
