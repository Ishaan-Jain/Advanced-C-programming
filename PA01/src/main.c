#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sort.h"

#define STANDARD        "abcdefghijklmnopqrstuvwxyz"
#define REVERSE         "zyxwvutsrqponmlkjihgfedcba"
#define QWERTY          "qwertyuiopasdfghjklzxcvbnm"

int main()
{
 	// Add test code here initially.
 	bool result;

        result =  check_lexicographical_order("ba",STANDARD);
        if(result == true)
            printf("True\n");
        else
        	printf("False\n");
        sort_lexicographically("HelloWorld", STANDARD);
	return EXIT_SUCCESS;
}
