#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat_str.h"


void concat_str(char *filename_in, char *filename_out) {
  // Your code here
  FILE * input = fopen(filename_in,"r");
  if(input == NULL)
  {
                fprintf(stderr,"[ERROR] in opening input file");
                exit(EXIT_FAILURE);
  }
  FILE *output = fopen(filename_out,"w");
  if(output == NULL)
  {
                fprintf(stderr,"[ERROR] in opening output file");
                exit(EXIT_FAILURE);
  }


  char string1[80];
  char string2[80];

  //int count = 0;
  
  // while(feof(input) == 0)
  // {
      // if(count == 0)
      // {
      //   fgets(string1,81,input);
      //   string1[strcspn(string1,"\n")] = 0;
      //   count = 1;
      // }
      
      // if(count == 1)
      // {
      //   fgets(string2,81,input);
      //   string2[strcspn(string1,"\n")] = 0;
      //   strcat(string1,string2);
      // // }

      while(feof(input) == 0)
    {
    if( fgets (string2, 80, input)!=NULL ) {
        string2[strcspn(string2, "\n")] = 0;
        strcat(string1,string2);
    }
    }
    strcat(string1,"\n");
     
      
  
  
  fprintf(output,"%s",string1);

  fclose(input);
  fclose(output);
  
  return;
  
}
