////////////////////////////////////////////////////////////////////////////////
///                           v  test_free_bits.c                            ///
////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>

#include "acutest.h"

/*
 * To test the functions, we will simply include the source file directly. In
 * this particular case, it doesn't lead to too much headache. Note that you
 * need only compile this file on its own now. Also note that including the 
 * source file directly here cna allow you to cut a few corners to make testing
 * easier.
 */
#include "../src/bitmap.c"

TEST_LIST = {
	{NULL, NULL}
};

////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
