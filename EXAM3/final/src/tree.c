////////////////////////////////////////////////////////////////////////////////
///                                  tree.c                                  ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h>
#include "tree.h"

TreeNode *alloc_tree_node(int value)
{
	TreeNode * node = malloc(sizeof(TreeNode));
	if(node == NULL)
	{
		fprintf(stderr,"[ERROR] is malloc of treenode");
		return NULL;
	}
	node->left = NULL;
	node->right = NULL;
	node->value = value;

	return node;
}

void free_tree_node(TreeNode *node)
{
	free(node);
	return;
}

TreeNode *insert_treenodes(int *in_order,int start, int end,int *pre_order,int pre_index,int count)
{
   if(pre_index > (count -1) || start > end)
   {
	   return NULL;
   }

   TreeNode * root = alloc_tree_node(pre_order[pre_index]);

   int i;
   int location;
   for(i = 0; i<= end ;i++)
   {
	   if(in_order[i] == root->value)
	   {
		   location = i;
	   }
   }

	root->left = insert_treenodes(in_order,start,location - 1,pre_order,pre_index + 1,count);
	root->right = insert_treenodes(in_order,location + 1,end,pre_order, pre_index + location - start + 1, count);

   return root;

}

int find_highest_path_weight(TreeNode * root,int count)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->left == NULL && root->right == NULL)
	{
        count = count + root->value;
		return count;
	}


	count = count + root->value;

	int countl = find_highest_path_weight(root->left,count);
	int countr = find_highest_path_weight(root->right,count);

	if(countl > countr )
	{
		return countl;
	}
	else
	{
		return countr;
	}

	
}

void free_allNodes(TreeNode *root)
{
	if(root == NULL)
	{
		return;
	}
	free_allNodes(root->left);
	free_allNodes(root->right);

	free_tree_node(root);
	return;

}

TreeNode *build_tree_from_files(char const *preOrderFile, char const *inOrderFile)
{

	FILE *input1 = fopen(preOrderFile,"r");
	if(input1 == NULL)
	{
		printf("Error in reading input1 file");
		return NULL;
	}
	FILE *input2 = fopen(inOrderFile,"r");
	if(input2 == NULL)
	{
		printf("Error in reading input2 file");
		return NULL;
	}

	int num;
	int ans;
	int count = 0;
	while(1)
	{
		  ans = fscanf(input2,"%d",&num);
		  if(ans > 0 && ans != EOF)
		  {
				count++;
		  }
		  else if(ans == EOF)
		  {
			  break;
		  }
	} 
    
	fseek(input2,0,SEEK_SET);

	int *pre_order = calloc(count,sizeof(int));
	int *in_order = calloc(count,sizeof(int)); 

	int i = 0;
	int j = 0;
	while(1)
	{
		  ans = fscanf(input1,"%d",&num);
		  if(ans > 0 && ans != EOF)
		  {
				pre_order[i] = num;
				i++;
		  }
		  else if(ans == EOF)
		  {
			  break;
		  }
	}


	while(1)
	{
		  ans = fscanf(input2,"%d",&num);
		  if(ans > 0 && ans != EOF)
		  {
				in_order[j] = num;
				j++;
		  }
		  else if(ans == EOF)
		  {
			  break;
		  }
	}

	int start = 0;
	int end = count - 1;
	int pre_index = 0;
	TreeNode *root = insert_treenodes(in_order, start, end,pre_order,pre_index,count);
	
	
	free(in_order);
	free(pre_order);
	fclose(input1);
	fclose(input2);

	return root;

}

int number_siblings(TreeNode *root, int count)
{
    if(root == NULL)
	{
		return count;
	}
    if(root->left == NULL && root->right == NULL)
    {
        return count;
    }

    if(root->left != NULL && root->right != NULL)
    {
        count++;
    }

    count = number_siblings(root->left, count);
    count = number_siblings(root->right, count);

    return count;   

}

#if !defined(GRADE_SUBLINGS)
int get_highest_path_weight(TreeNode *root)
{
    int weight = 0;
    weight = find_highest_path_weight(root,weight);
    return weight;
}
#endif

#if !defined(GRADE_PATH_WEIGHT)
int count_siblings(TreeNode *root)
{
    int count = 0;
    count = number_siblings(root, count);
    return count;
}
#endif

////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
