#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void swap (char *S1, char *S2);

void
swap (char *S1, char *S2)
{

  char temp4 = *S1;
  *S1 = *S2;
  *S2 = temp4;

 // printf ("S1 = %c\n", *S1);
 // printf ("S2 = %c\n", *S2);

  return;
}

int
mylen (char const *p)
{
  int z = 0;
  int k = 0;
  while (p[k] != '\0')
    {
      z++;
      k++;
    }

  return z;
}

#ifndef GRADE_SORT
bool
check_lexicographical_order (char const *phrase, char const *alphabet)
{
  // TODO
  // See README.md
  int i, j, k;
  int min;
  int len1 = 26;
  int value[26];
  int mylen (char const *);
  int len = mylen (phrase);


  value[0] = 1;
  for (k = 1; k < len1; k++)
    {
      value[k] = value[k - 1] + 10;
    }

  int index;
  int temp1[30], temp2[30];
  for (i = 0; i < 30; i++)
    {
      temp1[i] = 500;
      temp2[i] = 0;
    }

  for (i = 0; i < len; i++)
    {
      for (k = 0; k < len1; k++)
	{
	  if (phrase[i] == alphabet[k])
	    {
	      index = k;
	    }
	  else if (phrase[i] + 32 == alphabet[k])
	    {
	      index = k;
	      temp2[i] = 1;
	    }

	}
      temp1[i] = value[index];
    }

  for (i = 0; i < len; i++)
    {
      if (temp2[i] == 1)
	{
	  temp1[i] = temp1[i] - 5;
	}
    }



  /* for( j = 0; j<30; j++)
     {
     printf("%d\n",temp1[j]);
     } */

  for (i = 0; i < len; i++)
    {
      min = i;
      for (j = i + 1; j < len; j++)
	{
	  // printf("uuuu");
	  if (temp1[min] > temp1[j])
	    {
	      min = j;
	      return false;
	    }
	}
      //printf("booo");         
    }

  return true;

}
#endif // GRADE_SORT undefined


#ifndef GRADE_CHECK
void
sort_lexicographically (char *phrase, char const *alphabet)
{
  // TODO
  // See README.md
  int i, j, k;
  int min;
  int len1 = 26;
  int value[26];
  int mylen (char const *);
  int len = mylen (phrase);


  value[0] = 1;
  for (k = 1; k < len1; k++)
    {
      value[k] = value[k - 1] + 10;
    }

  int index;
  int temp1[30], temp2[30];
  for (i = 0; i < 30; i++)
    {
      temp1[i] = 500;
      temp2[i] = 0;
    }

  for (i = 0; i < len; i++)
    {
      for (k = 0; k < len1; k++)
	{
	  if (phrase[i] == alphabet[k])
	    {
	      index = k;
	    }
	  else if (phrase[i] + 32 == alphabet[k])
	    {
	      index = k;
	      temp2[i] = 1;
	    }

	}
      temp1[i] = value[index];
    }

  for (i = 0; i < len; i++)
    {
      if (temp2[i] == 1)
	{
	  temp1[i] = temp1[i] - 5;
	}
    }


  /*for( j = 0; j<30; j++)
     {
     printf("%d\n",temp1[j]);
     }*/


  char *temp3 = (char *) malloc ((len + 1) * sizeof (char));
  strcpy (temp3, phrase);

  for (i = 0; i < len; i++)
    {
      if (i + 1 < len)
	{
	  min = i;
	  for (j = i + 1; j < len ; j++)
	    {
	      // printf("uuuu");
	      
              // printf("t = %d\n", min);
	      if (temp1[min] > temp1[j])
		{
		  min = j;
		  // int temp5 = temp1[i];
		  // temp1[i] = temp1[j];
		  // temp1[j] = temp5;

		  //swap(&phrase[i],&phrase[min]);
		}
	    }
	  // printf("b = %d\n",min); 
	  swap (&temp3[i], &temp3[min]);
	  int temp5 = temp1[min];
	  temp1[min] = temp1[i];
	  temp1[i] = temp5;
	}
    }

  //strcpy(phrase,temp3);
 // *phrase = *temp3;

  //char temp4[30];
  //strcpy(temp4,phrase);

    for (j = 0; j < len; j++)
    {
      phrase[j] = temp3[j];
     // printf ("%c\n", phrase[j]);
    }


 // free (temp3);
  return;




}
#endif // GRADE_CHECK undefined
