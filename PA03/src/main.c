////////////////////////////////////////////////////////////////////////////////
//                                   main.c                                   //
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>  
#include <stdlib.h>
#include <errno.h>
#include <string.h> 
 
#include "qsort.h"

int main(int argc, char **argv)
{
	/*
 	 * As always, this function is not a required function for you to 
 	 * implement. Use main() to quickly run your code however you wish.
 	 * In the end though, you should have comprehensive unit tests under
 	 * the tests directory. I include some code below to give an example
 	 * of how you could call your functions to form a complete program
 	 * that reads integers from one file, sorts them, and writes the
 	 * integers into another file in sorted order. This example code by
 	 * itself does a poor job of testing the required functionalities.
 	 * YOU MUST SPEND TIME WRITING GOOD TESTS!
 	 */

	// We are going to assume the input file name comes in trough argv[1]
	// and that the output file name comes in through argv[2].
	if(argc != 3) {
		fprintf(stderr, "[ERROR] Usage: %s <input file name>" \
				" <output file name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Open the input file for reading.
	FILE *inputFile = fopen(argv[1], "r");
	if(inputFile == NULL) {
		fprintf(stderr, "[ERROR] in %s() at line %d: fopen failed" \
				" - %s.\n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	// Open the output file for writing. Note that, as the specification for
	// the fopen function says, opening a file for writing overwrites its
	// contents. If the file does not exist, it is created.
	FILE *outputFile = fopen(argv[2], "w");
	if(outputFile == NULL) {
		fprintf(stderr, "[ERROR] in %s() at line %d: fopen failed" \
				" - %s.\n", __func__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	// The cursor position for both files is at the very beginning of the
	// files. Let's count the number of integers in the input file.
	int count = count_int_from_file(inputFile);
	if(count == COUNT_FAIL) {
		fprintf(stderr, "[ERROR] could not count the number of" \
				" integers from the input file.");
		exit(EXIT_FAILURE);
	}
	printf("There are %d integers in %s.\n", count, argv[1]);

	// The count int function should have restored the cursor position
	// to whatever it was before it was called, which in this case, would
	// be the beginning of the input file. Thus, we can read the integers.
	// Use malloc here to allocate the array since the size depends on the
	// input to the program. It is absolutely not necessary to do so, and
	// you do not need to use malloc in your code or in the unit tests.
	int *buffer = malloc(count * sizeof(int));
	if(buffer == NULL) {
		// Unlikely this happens. Don't worry about it.
		fprintf(stderr, "[ERROR] could not allocate the buffer.\n");
		exit(EXIT_FAILURE);
	}
	int read = read_int_from_file(inputFile, buffer, count);
	printf("%d integers were read from %s.\n", read, argv[1]);

	// We then sort the integers in ascending order.
	sort_int_with_qsort(buffer, count);

	// And write the sorted array into the output file.
	int write = write_int_to_file(outputFile, buffer, count);
	printf("%d integers were written to %s.\n", write, argv[2]);	

	// Close the input and output files. Recall that we don't bother 
	// checking if these functions succeed. We assume they do.
	fclose(inputFile);
	fclose(outputFile);
	return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
//                                 END OF FILE                                //
////////////////////////////////////////////////////////////////////////////////
