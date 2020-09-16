//typeCode.c
//includes code to decode typeCode
//Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

char decodeTypeCodeNumber(uint8_t num)
{
	static const char lookup[64] = 
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y', 'Z', '#', '#',
		'#', '#', '#', '_', '#', '#', '#',
		'#', '#', '#', '#', '#', '#', '#',
		'#', '#', '#', '#', '#', '0', '1',
		'2', '3', '4', '5', '6', '7', '8',
		'9', '#', '#', '#', '#', '#', '#'
	};
	char result = lookup[num];
	return result;
}