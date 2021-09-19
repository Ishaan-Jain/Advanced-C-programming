#include <stdlib.h>
#include <stdio.h>

#include "encode.h"

void encode(FILE *inputFile, Code *codingTable, BitWriter *writer)
{
	while(1) {
		int ch = fgetc(inputFile);

		if(ferror(inputFile)) {
			exit(EXIT_FAILURE);
		}

		if(feof(inputFile)) {
			break;
		}

		Code code = codingTable[ch];
		write_buffer(code, writer);
	}
}

void write_buffer(Code code, BitWriter *writer)
{
	if(code.numBits <= (8 - writer->numBits)) {

		unsigned int mask = code.code << writer->numBits;
		// Zero out non-data bits.
		writer->buffer = writer->buffer | mask; // Assuming buffer has zeroes where there is no data.
		writer->numBits += code.numBits;

		if(writer->numBits == 8) {
			// Its own function maybe? flush_buffer().
			fputc(writer->outputFile, writer->buffer);
			writer->buffer = 0;
			writer->numBits = 0;
		}

	} else {

		// Code: 11011
		// bitsToWrite = 3
		// mask = 1111 1111 ; mask >> (32 - bitsToWrite)
		// mask = 0000 0111 
		// mask & code
		//
		// mask = 1111 1111
		// mask = ~(mask << bitsToWrite) -> 1111 1000
		// mask = ~mask -> 0000 0111


		int bitsToWrite = 8 - writer->numBits;
		unsigned int mask = 0xffffffff; //11111 >> 2 = 00111
		mask = mask >> (32 - bitsToWrite); // Isolate bitsToWrite LSBs.
		int firstWrite = code.code & mask;

		// Repeat of logic above. Flush buffer definitely happens.

		int numBitsLeft = code.numBits - bitsToWrite;
		// Repeat logic.

	}
}
