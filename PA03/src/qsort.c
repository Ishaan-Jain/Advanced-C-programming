////////////////////////////////////////////////////////////////////////////////
//                                   qsort.c                                  //
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "qsort.h"
#include <stdlib.h>


#if	!defined(GRADE_READ_INT) && 	\
	!defined(GRADE_WRITE_INT) && 	\
	!defined(GRADE_COMPARE_INT) && 	\
	!defined(GRADE_SORT_INT)
int count_int_from_file(FILE *stream)
{
	/*
 	 * Count the total number of integers in the file pointed to by 'stream'
 	 * and return the count. If the input file contains '124\n 378\n -56\n', 
 	 * this function should count and return 3. Do not count individual 
 	 * digits '1', '2', '4', etc. This function must have no side effect 
 	 * (Hint: you must preserve file cursor position, error flags, etc. if 
 	 * you think they might be affected by this function)! If this function
 	 * encounters any error, it should return COUNT_FAIL (defined in qsort.h
 	 * ).
 	 */
	int count = 0;
        char ch[128];   
        //long int answer;
        //int num; 
        char *remaining;
		errno = 0;
       
        while(fgets(ch,128,stream )!= NULL)
        {
        	    if(strtol(ch, &remaining,10) == 0)
				{
					fprintf(stderr,"[ERROR] check input\n");
					return COUNT_FAIL;
				}
                //num = answer;
                if(errno == 0)
                {
                    count = count + 1;   
                }
				else
				{
					return COUNT_FAIL;
				}   
        }       
        
        int cur =  fseek(stream,0,SEEK_SET);
        if(cur != 0 )
        {
        	fprintf(stderr,"[ERROR] in resetting cursor");
            return COUNT_FAIL;
        }
        return count;  

}
#endif // GRADE_COUNT_INT (essentially)



#if 	!defined(GRADE_COUNT_INT) &&	\
	!defined(GRADE_WRITE_INT) &&	\
	!defined(GRADE_COMPARE_INT) &&	\
	!defined(GRADE_SORT_INT)
int read_int_from_file(FILE *stream, int *buffer, int size)
{
	/*
 	 * Read as many integers as possible up to 'size' from the input file,
 	 * one at a time, into 'buffer'. Start reading from the current cursor
 	 * position. 'buffer' should be filled starting with 'buffer[0]' and
 	 * onwards. Return the number of integers read. Return READ_FAIL if an
 	 * error occurred while handling the input file. The file cursor position
 	 * should end up right after the last integer read (which could be the
 	 * end of the file).
 	 */
             
         int number;
         int i = 0;
         int cur;
         int count = 0;
         
         while(1)
         {
                if(fscanf(stream,"%d",&number) == 1 && i <size)
                {
         		buffer[i] = number;
                	i++;
                	count++;
                	if(i == size)
                	{
                			cur = fseek(stream,1,SEEK_CUR);
                        	if(cur != 0 )
        			        {	
                				fprintf(stderr,"[ERROR] in resetting cursor");
                				return READ_FAIL;
        			        }
                        
                	}
                 }	
                 
                 if(feof(stream))
                 {
                 	break;
                 }
         }
       
         return count; 
}     
#endif // GRADE_READ_INT (essentially)


#if 	!defined(GRADE_COUNT_INT) &&	\
	!defined(GRADE_READ_INT) &&	\
	!defined(GRADE_COMPARE_INT) &&	\
	!defined(GRADE_SORT_INT)
int write_int_to_file(FILE *stream, int *buffer, int size)
{
	/*
 	 * Write 'size' integers from 'buffer' into the output file pointed to
 	 * by 'stream'. The integers should be appended to the file; that is,
 	 * they should be written after the last integer already in the output
 	 * file, with at least one white-space character of separation. The
 	 * function should return the number of integers written to the output
 	 * file. If, for some reason, the function encounters an error while
 	 * handling the output file, it should return WRITE_FAIL.
 	 */
         int count = 0;
         for(int i = 0; i < size; i++)
         {
         	if(fprintf(stream,"%d\n",buffer[i]))
			{
				count++;
			}  
			else
			{
				return WRITE_FAIL;
			}
                

         }
         
         return count;
}
#endif // GRADE_WRITE_INT (essentially)


#if	!defined(GRADE_COUNT_INT) &&	\
	!defined(GRADE_READ_INT) &&	\
	!defined(GRADE_WRITE_INT) &&	\
	!defined(GRADE_SORT_INT)
int compare_int(const void *first, const void *second)
{
	/*
 	 * See 'man qsort' for a complete description + example of how to
 	 * write this function and how it is used by qsort(). Recall that this
 	 * function should return a negative integer if 'first' ought to be
 	 * sorted before 'second', a positive integer if 'first' ought to be
 	 * sorted after 'second', and zero if the order is undefined (which is
 	 * the case when 'first' and 'second' point to the same integer value
 	 * for example).
 	 */
	 
	 return (*(int*)first - *(int*)second);

}
#endif // GRADE_COMPARE_INT (essentially)


#if	!defined(GRADE_COUNT_INT) &&	\
	!defined(GRADE_READ_INT) &&	\
	!defined(GRADE_WRITE_INT) &&	\
	!defined(GRADE_COMPARE_INT)
void sort_int_with_qsort(int *buffer, int size)
{
	/*
 	 * Sort the integers in 'buffer' in ascending order using qsort. Your
 	 * qsort call should be using the compare_int function from this file.
 	 */
	  qsort(buffer,size,sizeof(int),compare_int);
}

#endif // GRADE_SORT_INT (essentially)
////////////////////////////////////////////////////////////////////////////////
//                                 END OF FILE                                //
////////////////////////////////////////////////////////////////////////////////
