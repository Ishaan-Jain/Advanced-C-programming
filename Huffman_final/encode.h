#ifndef __ENCODE_H__
#define __ENCODE_H__

#include <stdlib.h>

typedef struct code {
	char value;
	int code; // LSB
	int numBits;
} Code;

typedef struct bitwriter {
	FILE *outpuFile;
	char buffer;
	int numBits;
} BitWriter;

void encode(FILE *inputfile, Code *codingTable, BitWriter *writer);

#endif
