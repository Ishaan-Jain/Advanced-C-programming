#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>

#include "tree.h"

int main(int argc ,char **argv){
    if(argc != 3)
    {
        printf("Usage problem");
        return 0;
    }
    char *input1 = argv[1];
    char *input2 = argv[2];

   Tree *tree = build_tree_from_files(input1,input2);
   printf("depth is = %d\n",tree->depth);
   print_path_from_root_to_node(tree,9);
   free_tree(tree);


    return 0;
}