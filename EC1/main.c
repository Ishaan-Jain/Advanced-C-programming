#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void number_needle(char *haystack,char *needle);

int main(int argc, char **argv)
{
	if(argc != 3)
        {
        	fprintf(stderr,"Usage: %s <Haystack> <Needle>\n",argv[0]);
                exit(EXIT_FAILURE);
        }
        
        number_needle(argv[1],argv[2]);
        return EXIT_SUCCESS;
    
}

void number_needle(char *haystack,char *needle)
{
	int i ;
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        int str;
        int count = 0;
        char *dumm = (char*)malloc((len1+1)*sizeof(char));
        char *Nstr = (char*)calloc((len2+1),sizeof(char));
        
        strcpy(dumm,haystack);
        for(i = 0; i <len1; i++ )
        { 
           if(len1 - i >= len2)
           { 
                 for(int z = 0; z<len2;z++)
                 {
                	 Nstr[z] = dumm[z];
                 }

                 str = strcmp(Nstr,needle);
                 for(int j = 0; j<len1; j++)
                 {
                	 dumm[j] = dumm[j+1];

                 }
                 dumm[strlen(dumm)+1] = 0;

          	 if(str == 0)
          	 {
                         count = count +1;
          	 }
           }
        }
        
       printf("%d\n",count);
       free(dumm);
       free(Nstr);
       return;      
}
