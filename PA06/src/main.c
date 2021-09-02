#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>

#include "merge.h"

int main(){
    char *input = "input.txt";
    char *output = "output.txt";

    int *arr;
    int size = 0;
    read_data(input, &arr, &size);
    int l,r;
    l = 0;
    r = size-1;
    merge_sort(arr, l, r);
    write_data(output,arr,size);

    return 0;
}