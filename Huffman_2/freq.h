#ifndef __FREQ_H__
#define __FREQ_H__

#define FREQ_SIZE 256

typedef struct freqEntry {
	int ch;
	int freq;
} FreqEntry;

FreqEntry *calculate_frequencies(char *filename);

#endif
