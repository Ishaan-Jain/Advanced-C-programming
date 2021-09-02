////////////////////////////////////////////////////////////////////////////////
///                                 count.c                                  ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "count.h"
int compare_count(const void *first, const void *second);

/*int compare_string(const void *first, const void *second)
{
        WordCount *a_1 = (WordCount*)first;
        WordCount *a_2 = (WordCount*)second;
        if(a_1 -> word < a_2 -> word )
        {
                return 1;
        }
        else if(a_1 -> word > a_2 -> word)
        {
                return -1;
        }
        else
        {
                return 0;
        }
}*/


int compare_count(const void *first, const void *second)
{
        WordCount *a_1 = (WordCount*)first;
        WordCount *a_2 = (WordCount*)second;
        if(a_1 -> count < a_2 -> count )
        {
                return 1;
        }
        else if(a_1 -> count > a_2 -> count)
        {
                return -1;
        }
        else
        {
                return 0;
        }
}


#if     !defined(GRADE_COUNT_WORDS) && \
        !defined(GRADE_PRINT_WORDS) && \
        !defined(GRADE_FREE_WORDS)
bool alloc_count_array(char *vocabFile, WordCount **countArray, int *size)
{
  /*
   * Read the vocabulary file 'vocabFile' and allocate an array of WordCount
   * structures of length equal to the number of words in the file using malloc.
   * The address of the allocation should be stored in '*countArray', and its
   * size should be stored in '*size'. Return false if any error occurs, true
   * otherwise.
   */
   FILE *vocab = fopen(vocabFile,"r");
   if(vocab == NULL)
   {
           fprintf(stderr,"[ERROR] in opening vocabulary file\n");
           return false;
   }

   char string[33];
   int count = 0;
   while(fgets(string,33,vocab) != NULL)
   {
        count++;
   }
   
   
   *countArray =  malloc(count*sizeof(WordCount));
   char string1[33] = "\0";
   int j = 0;
   fseek(vocab,0,SEEK_SET);
   while(fgets(string1,33,vocab) != NULL && j < count)
   {      
        //countArray[j]-> =  malloc(sizeof(WordCount));
        for(int i = 0; i<33; i++)
        {
                if(string1[i] == '\n')
                {
                        string1[i] = 0;
                }
                
        }
        for(int i = 0; i<33; i++)
        {       
                int c = string1[i];
                if(isspace(c) != 0)
                {
                        string1[i] = 0;
                }
                
        }
        //countArray[j]->word =  malloc((MAX_WORD_LENGTH));
        strcpy((*countArray)[j].word,string1);
        (*countArray)[j].count = 0;
        j++;
   }
   
   *size = count;
   fclose(vocab);
   return true;
}
#endif // GRADE_ALLOC_WORDS (essentially)


#if     !defined(GRADE_ALLOC_WORDS) && \
        !defined(GRADE_PRINT_WORDS) && \
        !defined(GRADE_FREE_WORDS)
bool count_words_from_file(char *inputFile, WordCount *countArray, int size)
{
    /*
     * Read 'inputFile' and count the number of occurrences of words into the
     * corresponding entries in 'countArray'. The input file may have multiple
     * lines. Words are case sensitive. Words will not span multiple lines.
     * Return false if an error occurs, true otherwise.
     */
       FILE *input = fopen(inputFile,"r");
       if(input == NULL)
       {
           fprintf(stderr,"[ERROR] in opening input file\n");
           return false;
       }
       
       char buf[32];
       int i = 0;
       while(i <size)
       {
                while( fscanf(input, "%s", buf) != EOF)
	        {
                        if(strcmp(countArray[i].word, buf) == 0)
                        {
                                countArray[i].count = countArray[i].count + 1;
                        }

                
	        }
                i++;
                fseek(input,0,SEEK_SET);
       }

        fclose(input);
        return true;


}
#endif // GRADE_COUNT_WORDS (essentially)


#if     !defined(GRADE_ALLOC_WORDS) && \
        !defined(GRADE_COUNT_WORDS) && \
        !defined(GRADE_FREE_WORDS)
bool print_words_descending_freq(WordCount *countArray, int size)
{
    /*
     * Print "<word> <count>" (excluding the double quotes), one word per line,
     * to the console, in descending order of frequency first, alphabetical
     * order second. This function will have sort the array (you should use
     * qsort for this purpose). Return false if any error occurs, return true
     * otherwise.
     */
     FILE *output = fopen("output.txt","w");
     if(output == NULL)
     {
        fprintf(stderr,"[ERROR] in opening output file\n");
        return false;
     }
     //qsort(countArray,size,sizeof(WordCount),compare_string);
     qsort(countArray,size,sizeof(WordCount),compare_count);
     int start = -1;
     int end = -1;
     int k = 0;
     int temp2 = -1;

     while(k < (size-1))
     {
             if(countArray[k].count == countArray[k+1].count && start == -1)
             {
                     start = k;
                     temp2 = start;
             }
            // else if(k != 0 && countArray[k-1].count == countArray[k].count && countArray[k].count != countArray[k+1].count && start != -1)
              else if(k != 0 && countArray[k-1].count == countArray[k].count && countArray[k].count != countArray[k+1].count && start != -1)
             
             {
                     end = k;
                     for (int j = start; j < end; j++) { 
                        for (int i = j + 1; i < end+1; i++) { 
                                // if(countArray[j].word[0] <= 96)
                                // {
                                //  countArray[j].word[0] += 32;      
                                // }
                                if (strcmp(countArray[j].word, countArray[i].word) > 0) {
                                        char temp[32];
                                        strcpy (temp, countArray[j].word); 
                                        strcpy (countArray[j].word, countArray[i].word); 
                                        strcpy (countArray[i].word, temp); 
                                }
                        }
                      }
                      temp2 = start;  
                      end = -1;
                      start = -1;
             }

             k++;

             
     }

     if(k !=0 && (k == (size-1)) && countArray[k-1].count == countArray[k].count && temp2 >= 0)
     {
             end = k;
                     for (int j = temp2; j < end; j++) { 
                        for (int i = j + 1; i < end+1; i++) { 
                                if (strcmp(countArray[j].word, countArray[i].word) > 0) {
                                        char temp[32];
                                        strcpy (temp, countArray[j].word); 
                                        strcpy (countArray[j].word, countArray[i].word); 
                                        strcpy (countArray[i].word, temp); 
                                }
                        }
                      }

     }
     /*for(int k = 0; k<size -1; k++)
     {       
             char temp[32];
             if(countArray[k].count == countArray[k+1].count)
             {       
                    
                     int res = strcmp(countArray[k].word,countArray[k+1].word);
                     if(res > 0)
                     {
                             strcpy(temp, countArray[k].word);
                             strcpy(countArray[k].word, countArray[k+1].word);
                             strcpy(countArray[k+1].word, temp);
                     }
             }
     }*/
     int i;
     for(i = 0;i < size;i++)
     {        
             if(i<size -1)
             {
                      fprintf(output,"%s %d\n",countArray[i].word,countArray[i].count);
             }
             else{
                      fprintf(output,"%s %d",countArray[i].word,countArray[i].count);
             }
            
             
     }

     fclose(output);
     return true;
}
#endif // GRADE_PRINT_WORDS (essentially)


#if     !defined(GRADE_ALLOC_WORDS) && \
        !defined(GRADE_COUNT_WORDS) && \
        !defined(GRADE_PRINT_WORDS)
bool free_count_array(WordCount *countArray)
{
    /*
     * Free the memory allocated to the count array.
     */
     free(countArray);
     return true;
}
#endif // GRADE_FREE_WORDS (essentially)
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
