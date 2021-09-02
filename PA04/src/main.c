////////////////////////////////////////////////////////////////////////////////
///                                 main.c                                   ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "count.h"


int main(int argc, char **argv)
{
  /*
   * As always, this file is present just for quick and dirty testing. Thorough
   * testing should be included in the unit test files. Below is an example
   * usage of the functions in a complete program. THIS DOES NOT CONSTITUTE
   * THOROUGH TESTING.
   */

   // Program inputs are fed using the command line.
   if (argc != 3) {
       printf("[ERROR] Usage: %s <vocab file> <intput file>", argv[0]);
       return EXIT_FAILURE;
   }

   // Allocate the count array. The pointer to the array is initialized to NULL,
   // its size is initialized to zero.
   WordCount *countArray = NULL;
   int countArraySize = 0;
   // The function call below will populate the pointer countArray with the
   // address (on the heap) of the array. That's why we are passing countArray
   // by address (Make sure you understand this!). Same story with
   // countArraySize.
   if ( !alloc_count_array(argv[1], &countArray, &countArraySize) ) {
       return EXIT_FAILURE;
   }

   // Count the word frequencies from the input file.
   if ( !count_words_from_file(argv[2], countArray, countArraySize) ) {
       return EXIT_FAILURE;
   }

   // Print the words and their frequencies in descending order.
   if ( !print_words_descending_freq(countArray, countArraySize) ) {
       return EXIT_FAILURE;
   }

   // Free the count array.
   if ( !free_count_array(countArray) ) {
       return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
