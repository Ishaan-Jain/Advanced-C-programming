////////////////////////////////////////////////////////////////////////////////
//                            test_convert_base.c                             //
////////////////////////////////////////////////////////////////////////////////

/**
 * This file contains the unit tests for the convert_base function. Fill in the
 * test functions with TEST_CHECK and TEST_MSG calls to thoroughly test out your
 * functions.
 */

#include <stdio.h>

#include "acutest.h"
#include "string.h"
#include "../src/convert.h"

void test_single_digit()
{
	// Test your convert_base function when the input is a single digit,
	// such as "1", "a", or "z".
	// Because the convert_base function outputs to stdout, we have provided
	// the macro TEST_STDOUT_EQUALS that can be used to compare its output
	// to some string. An example usage is shown below.
	TEST_STDOUT_EQUALS(convert_base("5", 10, 2), "101\n");
}

void test_many_digit()
{
	// Now, let the input number be more than one digit long.
	TEST_STDOUT_EQUALS(convert_base("670000", 10, 16), "a3930\n");
}

void test_invalid_number_base_pair()
{
	// Test your function with a number that isn't possible with the 
	// given input base (e.g. convert_base("333", 2, 10) which is invalid
	// since 333 is not a binary number).
	TEST_STDOUT_EQUALS(convert_base("asf", 16, 10),"");
}

void test_invalid_base()
{
	// Test your function with invalid bases (less than 2, greater than 36).
	TEST_STDOUT_EQUALS(convert_base("23", 1, 78),"");
}

TEST_LIST = {
  { "test_single_digit", test_single_digit },
  { "test_many_digit", test_many_digit },
  { "test_invalid_number_base_pair", test_invalid_number_base_pair },
  { "test_invalid_base", test_invalid_base },
  { NULL, NULL }
};
////////////////////////////////////////////////////////////////////////////////
//                                END OF FILE                                 //
////////////////////////////////////////////////////////////////////////////////
