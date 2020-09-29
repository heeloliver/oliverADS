// typeCode.c
// includes code to decode typeCode and data content type
// Oliver Mulcahy (opm@ucsc.edu)

#ifndef ADS_H
#define ADS_H

#include "ads.h"

#endif

// Decodes type code number with a lookup table.
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

// Decodes type code.
char* typeCodeLookup(int tc)
{
	char *typeCode = malloc(36);

	if ((tc > 0) && (tc <= 4)) 
	{
		typeCode = "Aircraft Identification";
	}
	else if ((tc > 4) && (tc <= 8))
	{
		typeCode = "Surface position";
	}
	else if ((tc > 8) && (tc <= 18))
	{
		typeCode = "Airborne position (w/ baro Altitude)";
	}
	else if (tc == 19)
	{
		typeCode = "Airborne velocities";
	}
	else if ((tc > 19) && (tc <= 22))
	{
		typeCode = "Airborne position (w/ GNSS Height)";
	}
	else if ((tc > 22) && (tc <= 27))
	{
		typeCode = "Reserved";
	}
	else if (tc == 28)
	{
		typeCode = "Aircraft status";
	}
	else if (tc == 29)
	{
		typeCode = "Target state and status information";
	}
	else if (tc == 31)
	{
		typeCode = "Aircraft operation status";
	}
	else
	{
		typeCode = "Unknown";
	}
	return typeCode;
}

// Decodes data content.
int dataContentLookup(int tc)
{
	int dataContent;

	if ((tc > 0) && (tc <= 4)) 
	{
		dataContent = AIRCRAFTIDEN;
	}
	else if ((tc > 4) && (tc <= 8))
	{
		dataContent = SURFACEPOS;
	}
	else if ((tc > 8) && (tc <= 18))
	{
		dataContent = AIRBORNEPOSBARO;
	}
	else if (tc == 19)
	{
		dataContent = AIRBORNEVELO;
	}
	else if ((tc > 19) && (tc <= 22))
	{
		dataContent = AIRBORNEPOSGNSS;
	}
	else if ((tc > 22) && (tc <= 27))
	{
		dataContent = RESERVED;
	}
	else if (tc == 28)
	{
		dataContent = AIRCRAFTSTAT;
	}
	else if (tc == 29)
	{
		dataContent = TARGETSTATE;
	}
	else if (tc == 31)
	{
		dataContent = AIRCRAFTOPSTAT;
	}
	else
	{
		dataContent = UNKNOWN;
	}

	return dataContent;
}
