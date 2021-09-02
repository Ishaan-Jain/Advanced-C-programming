////////////////////////////////////////////////////////////////////////////////
///                                  main.c                                  ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

#include "list.h"
#include "cake.h"

int main(int argc, char * * argv)
{
	if(argc != 3)
	{
		fprintf(stderr,"Error in input\n");
		exit(EXIT_FAILURE);
	}
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int value = eliminate(x,y);
	printf("The ans is = %d\n",value);
	return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
