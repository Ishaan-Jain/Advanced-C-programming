////////////////////////////////////////////////////////////////////////////////
//                                   main.c                                   //
////////////////////////////////////////////////////////////////////////////////
// Note: the amount of commenting that you see in this file is just for 
// pedagogical purposes. Do not comment your own code like this. Always remember
// that good, clean code tells its own story, and does not need comments to
// effectively communicate to its reader what it is doing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// We need errno.h because it defines the global error code status variable 
// errno that we need to identify whether standard library function calls
// (e.g. strtol()) succeeded or not. We will need string.h for the function
// strerror().

#include "convert.h"

/**
 * validate_base__: helper function that validates the bases passed as arguments
 * to the program.
 */
void validate_base__(char const * baseStr)
{
	errno = 0;
	char * endptr;
	// Call strtol() to convert the base to an integer. We let the function
	// attempt the conversion and check later whether it succeeded or not.
	long int base = strtol(baseStr, &endptr, 10);
	// If errno is non-zero now, then strtol() must have encountered a 
	// conversion error. The function strerror() maps the error code in
	// errno to a human readable string that describes the error.
	if(errno != 0) {
		fprintf(stderr, "[ERROR] %s: [errno: %d] %s\n", __func__, \
				errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
	// Since errno is still zero, strtol() encountered no error. However, it
	// could still happen that no digits were read. We check whether that's
	// the case by comparing endptr to the address of the input string.
	if(endptr == baseStr) {
		fprintf(stderr, "[ERROR] %s: no digits could be read from" \
				" '%s'\n", __func__, baseStr);
		exit(EXIT_FAILURE);
	}
	// There could be extraneous characters that could not be converted at
	// the end of the string. If so, we will consider that an invalid input.
	if(*endptr != '\0') {
		fprintf(stderr, "[ERROR] %s: extraneous characters at the end of" \
				" '%s'\n", __func__, baseStr);
		exit(EXIT_FAILURE);
	}
	// The base was read succesfully. We just need to make sure it is within
	// the prescribed range before moving on.
	if(base < 2 || base > 36) {
		fprintf(stderr, "[ERROR] %s: specified base %ld is" \
				" out-of-range\n", __func__, base);
		exit(EXIT_FAILURE);
	}
}

/**
 * validate__: helper function that validates the user input.
 */
void validate__(int argc, char ** argv)
{
	// The invoking command must contain exactly four arguments.
	if(argc != 4) {
		fprintf(stderr, "[ERROR] usage: %s <operand> <input base>" \
				" <output base>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	// Validate both the input base and the output base.
	validate_base__(argv[2]);
	validate_base__(argv[3]);
}

int main(int argc, char ** argv)
{
	// Begin by validating the user input as much as possible. This is a
	// common principle: validate user input as soon as possible. Note that
	// we cannot validate argv[1] yet, since it takes the whole program
	// to do so.
	validate__(argc, argv);
	// Convert the bases into integers. We know, thanks to the validation
	// helpers, that this operation will succeed.
	int inputBase = (int) strtol(argv[2], NULL, 10);
	int outputBase = (int) strtol(argv[3], NULL, 10);
	// Call the base conversion function.
	convert_base(argv[1], inputBase, outputBase);
	return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
//                                END OF FILE                                 //
////////////////////////////////////////////////////////////////////////////////
