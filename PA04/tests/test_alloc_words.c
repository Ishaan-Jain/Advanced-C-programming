////////////////////////////////////////////////////////////////////////////////
///                           test_alloc_words.c                             ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>

#include "acutest.h"
#include "../src/count.h"

void test_nonexistent_file()
{     
    WordCount *countArray = NULL;
    int countArraySize = 0;
    char *vocabFile = "random.txt";
    bool result = alloc_count_array(vocabFile, &countArray, &countArraySize);
    TEST_CHECK(result == false && countArraySize == 0);
}

void test_vocab_file_with_one_word()
{
    WordCount *countArray = NULL;
    int countArraySize = 0;
    char *vocabFile = "tests/inputs/vocab1";
    bool result = alloc_count_array(vocabFile, &countArray, &countArraySize);
    TEST_CHECK(countArraySize == 1 && result == true);
}

void test_vocab_file_with_multiple_words()
{
    WordCount *countArray = NULL;
    int countArraySize = 0;
    char *vocabFile = "tests/inputs/vocab3";
    bool result = alloc_count_array(vocabFile, &countArray, &countArraySize);
    TEST_CHECK(countArraySize == 3 && result == true);
}

// Add more test cases below until you have a thorough test suite.

TEST_LIST = {
  { "test_nonexistent_file", test_nonexistent_file },
  { "test_vocab_file_with_one_word", test_vocab_file_with_one_word },
  { "test_vocab_file_with_multiple_words", test_vocab_file_with_multiple_words },
  { NULL, NULL }
};
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
