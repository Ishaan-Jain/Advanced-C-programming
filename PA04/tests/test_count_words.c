////////////////////////////////////////////////////////////////////////////////
///                           test_count_words.c                             ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#include "acutest.h"
#include "../src/count.h"

void test_nonexistent_file()
{

}

void test_empty_file()
{

}

void test_single_line_file()
{

}

void test_multi_line_file()
{

}

// Add more test cases below until you have a thorough test suite.

TEST_LIST = {
  { "test_nonexistent_file", test_nonexistent_file },
  { "test_empty_file", test_empty_file },
  { "test_single_line_file", test_single_line_file },
  { "test_multi_line_file", test_multi_line_file },
  { NULL, NULL }
};
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
