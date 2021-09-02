////////////////////////////////////////////////////////////////////////////////
///                                 count.h                                  ///
////////////////////////////////////////////////////////////////////////////////
#ifndef __COUNT_H__
#define __COUNT_H__

#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 32

typedef struct _WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

bool alloc_count_array(char *vocabFile, WordCount **countArray, int *size);
bool count_words_from_file(char *inputFile, WordCount *countArray, int size);
bool print_words_descending_freq(WordCount *countArray, int size);
bool free_count_array(WordCount *countArray);

#endif // __COUNT_H__
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                                ///
////////////////////////////////////////////////////////////////////////////////
