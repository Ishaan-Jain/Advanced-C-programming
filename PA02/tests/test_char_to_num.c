////////////////////////////////////////////////////////////////////////////////
//                            test_char_to_num.c                              //
////////////////////////////////////////////////////////////////////////////////

/**
 * This file contains the unit tests for the convert_char_to_num function. Fill
 * in the test functions with TEST_CHECKs and TEST_MSGs calls to thoroughly test
 * your functions out.
 */

#include <stdio.h>

#include "acutest.h"
#include "string.h"
#include "../src/convert.h"

void test_invalid_input()
{
	// Test the convert_char_to_num function with an invalid input
	// (e.g. '>', '%' which don't correspond to any numbers).
	int num;
        num =  convert_char_to_num('%');
        TEST_CHECK(num == -1);
        TEST_MSG("Num = %d",num);
}

void test_0_to_9()
{
	int num;
        num =  convert_char_to_num('9');
        TEST_CHECK(num == 9);
        TEST_MSG("Num = %d",num);
}

void test_a_to_z()
{
	int num;
        num =  convert_char_to_num('b');
        TEST_CHECK(num == 11);
        TEST_MSG("Num = %d",num);
}

TEST_LIST = {
  { "test_invalid_input", test_invalid_input },
  { "test_0_to_9", test_0_to_9 },
  { "test_a_to_z", test_a_to_z },
  { NULL, NULL }
};
////////////////////////////////////////////////////////////////////////////////
//                                END OF FILE                                 //
////////////////////////////////////////////////////////////////////////////////
