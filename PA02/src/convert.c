////////////////////////////////////////////////////////////////////////////////
//                                 convert.c                                  //
////////////////////////////////////////////////////////////////////////////////

/**
 * THIS FILE CONTAINS BAD CODE! Your task in this assignment is to correct the
 * code in this file until the functions behave as desired. See the README.md 
 * for a complete description of what the requirements are for the functions.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "convert.h"

#if !defined(GRADE_NUM_TO_CHAR) && !defined(GRADE_CONVERT_BASE)
int convert_char_to_num(char c) 
{
	if (c >= '0' && c <= '9')
    		return c - '0';
  	else if (c >= 'a' && c <= 'z')
    		return c - 'a' + 10;
  	else
    		return -1;  // -1 means invalid
}
#endif

#if !defined(GRADE_CHAR_TO_NUM) && !defined(GRADE_CONVERT_BASE)
char convert_num_to_char(int n) 
{
	if (n >= 0 && n <= 9)
    		return n + '0';
  	else if (n >= 10 && n <= 35)
    		return n + 'a' - 10;
  	else
    		return 0; // 0 means invalid
}
#endif

#if !defined(GRADE_CHAR_TO_NUM) && !defined(GRADE_NUM_TO_CHAR)
void convert_base(char * numStrRep, int inputBase, int outputBase)
{       
        if( inputBase > 36 || inputBase < 2 )
        {
        	fprintf(stderr, "[ERROR] %s: specified base %d is" \
                                " out-of-range\n", __func__, inputBase);
                return;
     
        }
        else if( outputBase > 36 || outputBase < 2)
        {
            fprintf(stderr, "[ERROR] %s: specified base %d is" \
                                " out-of-range\n", __func__, outputBase);
            return;

        }
	// First, we are going to convert the number into a base
	// ten integer value.
        int power = 1;
        int num = 0;
  	int valLen = strlen(numStrRep);
	// Loop through each digit of the input number, starting with the
	// least significant digit.
	for (/*unsigned*/ int i = valLen - 1; i >= 0; i--) {
    		int n = convert_char_to_num(numStrRep[i]);
		if (n == -1 || n >= inputBase) {
			fprintf(stderr, "[ERROR] %s: an error occurred.\n", __func__);
      			return;
    		}
		// Accumulate the converted digit multiplied with the
		// current base power into num.
		num += n * power;
		// Update the base power for the next digit to the left.
		power *= inputBase;
	}

	// Second, we are going to figure out what the maximum
	// divisor for our number is.
	int divisor = 1;
        int len = 0;
        //float s = num / (divisor * outputBase);
	while (num / (divisor * outputBase)  > 0)
        {
		divisor *= outputBase;
                len++;
        }
              
        if(num % 2 != 0)
        {
            divisor++;
        }

       // printf("len = %d\n",len);
       // printf("div = %d\n",divisor);
  
	// Third, we are going to divide our number by the divisor
	// to isolate each digit, starting with the most significant
	// digit.
        int num1 = num;
        char *ans = (char*)malloc((len+1)*sizeof(char));
        int i = 0;
        int div;
  	while (divisor > 0) {
    		char ch = convert_num_to_char(num1 % outputBase);
                num1 = num1 / outputBase;
                div = num1 / divisor;
                char ch1 = convert_num_to_char(div);
    		if (ch1 == 0) {
			fprintf(stderr, "[ERROR] %s: an error occurred.\n", __func__);
			return;
		}
                ans[i] = ch;
                i++;	
    	      	//printf("i = %c\n", ch);
    		divisor /= outputBase;
  	}
        for(int j = len; j >= 0; j--)
        {
            printf("%c",ans[j]);
        }
	printf("\n");
        free(ans);
}
#endif
////////////////////////////////////////////////////////////////////////////////
//                                END OF FILE                                 //
////////////////////////////////////////////////////////////////////////////////
