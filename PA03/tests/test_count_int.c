////////////////////////////////////////////////////////////////////////////////
//                              test_count_int.c                              //
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#include "acutest.h"
#include "../src/qsort.h"

void test_with_empty_file(void)
{       
        FILE *fptr = fopen("tests/inputs/empty.txt","r");
        if(fptr == NULL)
        {
        	fprintf(stderr,"[ERROR] in opening file\n");
                exit(EXIT_FAILURE);
        }
  
	int res = count_int_from_file(fptr);
        fclose(fptr);
        TEST_CHECK(res == 0);
        TEST_MSG("Count is %d",res);
} 

/*void test_with_single_file(void)
{       
        FILE *fptr = fopen("tests/inputs/single.txt","r");
        if(fptr == NULL)
        {
        	fprintf(stderr,"[ERROR] in opening file\n");
                exit(EXIT_FAILURE);
        }
  
	int res = count_int_from_file(fptr);
        fclose(fptr);
        TEST_CHECK(res == 1);
        TEST_MSG("Count is %d",res);
} */
 
void test_with_small_file(void)
{
        FILE *fptr = fopen("tests/inputs/small.txt","r");
        if(fptr == NULL)
        {
                fprintf(stderr,"[ERROR] in opening file\n");
                exit(EXIT_FAILURE);
        }
  
        int res = count_int_from_file(fptr);
        fclose(fptr);
        TEST_CHECK(res == 10);
        TEST_MSG("Count is %d",res);
} 


void test_with_medium_file(void)
{
        FILE *fptr = fopen("tests/inputs/medium.txt","r");
        if(fptr == NULL)
        {
                fprintf(stderr,"[ERROR] in opening file\n");
                exit(EXIT_FAILURE);
        }

        int res = count_int_from_file(fptr);
        fclose(fptr);
        TEST_CHECK(res == 30);
        TEST_MSG("Count is %d",res);
}

TEST_LIST = {
  {"empty_file",test_with_empty_file},
  {"small_file",test_with_small_file},
  {"medium_file",test_with_medium_file},
  //{"single_file",test_with_single_file},
  {NULL, NULL}
};
////////////////////////////////////////////////////////////////////////////////
//                                 END OF FILE                                //
////////////////////////////////////////////////////////////////////////////////
