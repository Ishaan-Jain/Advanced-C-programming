#include <stdlib.h>
#include <stdio.h>
#include "bitmap.c"

int main(int argc ,char **argv)
{
    if(argc != 2)
    {
        printf("[ERROR] in input");
        return 0;
    }

    int x = atoi(argv[1]);
    init_bitmap();

    int res = alloc_bits(x);
    for(int i = 0;i <BITMAP_SIZE; i++)
    {
        if(res == 0)
        {
        printf("%x\n",bitmap[i]);
        }
    }
    printf("%x\n",bitmap[0]);
    free_bit(1);
    free_bit(2);
    printf("%x\n",bitmap[0]);

    res = alloc_bits(3); 
    printf(" res = %d\n",res);
    printf("%x\n",bitmap[0]);
    return 1;
}