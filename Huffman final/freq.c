#include <stdio.h>
#include <stdlib.h>

#include "freq.h"

int compare(void const *a, void const *b)
{
	FreqEntry *first = (FreqEntry *) a;
	FreqEntry *second = (FreqEntry *) b;

	if(first->freq < second->freq) {
		return -1;
	} else if(first->freq > second->freq) {
		return 1;
	} else {
		return 0;
	}
}


FreqEntry *calculate_frequencies(char *filename)
{
	FreqEntry *freqArray = malloc(FREQ_SIZE * sizeof(FreqEntry));
	if(freqArray == NULL) {
		exit(EXIT_FAILURE);
	}

	// Alternative: memset()
	for(int i = 0; i < FREQ_SIZE; i++) {
		freqArray[i].ch = i;
		freqArray[i].freq = 0;
	}

	FILE *fptr = fopen(filename, "r");
	if(fptr == NULL) {
		exit(EXIT_FAILURE);
	}

	while(1) {
		int ch = fgetc(fptr);

		if(ferror(fptr)) exit(EXIT_FAILURE);

		if(feof(fptr)) break;

		freqArray[ch].freq++;
	}

	fclose(fptr);

	qsort(freqArray, FREQ_SIZE, sizeof(FreqEntry), compare);

	return freqArray;
}
