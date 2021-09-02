////////////////////////////////////////////////////////////////////////////////
///                                  merge.c                                 ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>

#include "merge.h"

#if     !defined(GRADE_WRITE) && \
        !defined(GRADE_MERGE) && \
	!defined(GRADE_MERGE_SORT)
bool read_data(char const *filename, int **arr, int *size)
{
	/*
 	 * 'filename' is the name of the input file, formatted just like the
 	 * input files in PA03. You will need to calculate the number of 
 	 * integers in the input file and alloacte the appropriate array size
 	 * on the heap for '*arr'. Return true if successful, false otherwise. 
 	 */

	  FILE *input = fopen(filename,"r");
	  if(input == NULL)
	  {
		  printf("Error in reading input file");
		  return false;
	  }
      
	  int count = 0;
	  int num = 0;
	  int ans = 0;

	  while(1)
	  {
		  ans = fscanf(input,"%d",&num);
		  if(ans > 0 && ans != EOF)
		  {
			  count++;
		  }
		  else if(ans == EOF)
		  {
			  break;
		  }
	  } 
    
	  fseek(input,0,SEEK_SET);
	  if(count != 0)
	  {
		  *arr = calloc(count,sizeof(int));

	  }
	  else 
	  {
		  *arr = NULL;
	  }
      
	  /*for(int h = 0; h < count; h++)
      {
		  arr[h] = (int*)calloc(1,sizeof(int));
	  }*/
	  int i = 0;
	  while(1)
	  {
		  ans = fscanf(input,"%d",&num);
		  if(ans > 0 && ans != EOF)
		  {
			  (*arr)[i] = num;
			  i++;
		  }
		  else if(ans == EOF)
		  {
			  break;
		  }
	  } 

	  *size = count;
	  fclose(input);

	  return true;
   
}
#endif


#if     !defined(GRADE_READ) && \
        !defined(GRADE_MERGE) && \
	!defined(GRADE_MERGE_SORT)
bool write_data(char const *filename, int const *arr, int size)
{
	/*
 	 * 'filename' is the name of the output file, formatted just like the
 	 * output files in PA03. Simply write the integers from 'arr' into the
 	 * output file. Return true if successful, false otherwise.
 	 */
	  FILE *output = fopen(filename,"w");
	  if(output == NULL)
	  {
		  printf("Error in opening output file");
		  return false;
	  }
	  int i = 0;
	  for( i = 0; i< size; i++)
	  {
		  fprintf(output,"%d\n",arr[i]);
	  }
	 /* for(int j = 0; j< size; j++)
	  {
		  free(arr[j]);
	  }
	  free(arr);*/
      
	  fclose(output);
	  return true;
}
#endif


#if     !defined(GRADE_READ) && \
        !defined(GRADE_WRITE) && \
	!defined(GRADE_MERGE_SORT)
void merge(int *arr, int l, int m, int r)
{
	/*
 	 * This function takes the two sorted regions with indices [l, m) and 
 	 * [m, r) and merges them together into the sorted region [l, r). This
 	 * function does not need to be recursive.
 	 */

	int size1 = m - l + 1;
	int size2 = r - m;
	int i = 0; 
	int j = 0;

	int *temp1 = (int*)calloc(size1,sizeof(int));
	int *temp2 = (int*)calloc(size2,sizeof(int));

	/*for(int g = 0; g< size1;g++)
	{
		printf("%d\n",temp1[g]);
	}*/

	while(i < size1 || j < size2)
	{
		if(i < size1)
		{
			temp1[i] = arr[l + i];
			i++;
		}

		if(j < size2)
		{
			temp2[j] = arr[m + j + 1];
			j++;
		}
	}

     
	i = 0;
	j = 0;
	int z = l;
	while(i < size1 && j < size2)
	{
		if(temp1[i] <= temp2[j])
		{
			arr[z] = temp1[i];
			i++;
		}
		else
		{
			arr[z] = temp2[j];
			j++;
		}
		z++;
	}
   
   for(i = i;i<size1;i++)
   {
	   arr[z] = temp1[i];
        z++;
   }

   for(j = j; j < size2 ;j++)
   {
	   arr[z] = temp2[j];
        z++;
   }

    
    free(temp1);
	free(temp2);
}
#endif

#if	!defined(GRADE_READ) && \
	!defined(GRADE_WRITE) && \
	!defined(GRADE_MERGE)
void merge_sort(int *arr, int l, int r)
{
	/*
 	 * This function is recursive. This goal is to sort the region [l, r)
 	 * of the original array 'arr'. Of course, initially, 'l' and 'r' should
 	 * be zero and the size of the original array respectively. To sort, you
 	 * should split the region down the middle, make recursive calls to
 	 * merge_sort() on both halves, and then merge the sorted havles with a
 	 * call to merge().
 	 */

	  
	  /*if(r <= l)// Base case
	  {
		  return;
	  }*/

      if(l <r){

		   int middle = (l + r)/2;
		   merge_sort(arr,l,middle);
	       merge_sort(arr,middle + 1,r);
        
	        merge(arr,l,middle,r);
	  }
}
#endif
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
