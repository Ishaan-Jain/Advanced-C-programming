#include <stdio.h>
#include <stdlib.h>
#include "concat_str.h"

// This helper function returns 0 if the two files are the same, and non-0 if otherwise
// You can use this function to build your tests
int diff(char *fname1, char *fname2) {
  char command[256];
  sprintf(command, "diff \"%s\" \"%s\"", fname1, fname2);
  return system(command);
}


int main() {
    char *inputFile = "input.txt";
    char *outputFile = "output.txt";
    char *outputFile2 = "output2.txt";
    concat_str(inputFile, outputFile);
    int ans = diff(outputFile2,outputFile);
    if(ans == 0)
    {
      printf("success");
    }
    
    return 0;
}
