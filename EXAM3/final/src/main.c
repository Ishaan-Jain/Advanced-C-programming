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

   TreeNode *root = build_tree_from_files(input1,input2);
   int weight = get_highest_path_weight(root);
   printf("The weight is %d\n", weight);
   int count = count_siblings(root);
   printf("The count is %d\n", count);
   free_allNodes(root);


    return 0;
}