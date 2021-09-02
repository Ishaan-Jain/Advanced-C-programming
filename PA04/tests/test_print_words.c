////////////////////////////////////////////////////////////////////////////////
///                           test_print_words.c                             ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "acutest.h"

#include "../src/count.h"

void test_wc_with_one_word()
{
   WordCount *countArray = NULL;
   int countArraySize = 0;
   char *vocabFile = "tests/inputs/vocab2";
   char *inputfile = "tests/inputs/input2";
   alloc_count_array(vocabFile, &countArray, &countArraySize);
   count_words_from_file(inputfile, countArray, countArraySize);
   bool result = print_words_descending_freq(countArray,countArraySize);
   TEST_CHECK(result == true);
   TEST_TWO_FILES_EQUAL("tests/expected/expected1", "output.txt");
}

/*void test_wc_with_multiple_words()
{
   WordCount *countArray = NULL;
   int countArraySize = 0;
   char *vocabFile = "tests/inputs/vocab3";
   char *inputfile = "tests/inputs/input3";
   alloc_count_array(vocabFile, &countArray, &countArraySize);
   count_words_from_file(inputfile, countArray, countArraySize);
   bool result = print_words_descending_freq(countArray,countArraySize);
   TEST_CHECK(result == true);
   TEST_TWO_FILES_EQUAL("tests/expected/expected3", "output.txt");
}*/

// Add more test cases below until you have a thorough test suite.

TEST_LIST = {
  { "test_wc_with_one_word", test_wc_with_one_word },
  //{ "test_wc_with_multiple_words", test_wc_with_multiple_words },
  { NULL, NULL }
};
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
