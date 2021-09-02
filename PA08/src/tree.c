////////////////////////////////////////////////////////////////////////////////
///                                  tree.c                                  ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include "tree.h"

TreeNode *insert_treenodes(int *in_order,int start, int end,int *pre_order,int pre_index,int count);
int find_depth(TreeNode * root,int count);
TreeNode *assign_parent(TreeNode *root,TreeNode *parent);
bool search(TreeNode *root,int value, int*arr,int *i);
void free_allNodes(TreeNode *root);


TreeNode *alloc_tree_node(int value)
{
	// Nothing special to be said here. Business as usual.
	TreeNode * node = malloc(sizeof(TreeNode));
	if(node == NULL)
	{
		fprintf(stderr,"[ERROR] is malloc of treenode");
		return NULL;
	}
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->value = value;

	return node;
}

void free_tree_node(TreeNode *node)
{
	// Nothing special to be said here either.
	free(node);
	return;
}

Tree *alloc_tree(int numNodes, int depth, TreeNode *root)
{
	// Meh.
	Tree *tree = malloc(sizeof(Tree));
	if(tree == NULL)
	{
		fprintf(stderr,"[ERROR] in malloc of tree");
		return NULL;
	}
	tree->numNodes = numNodes;
	tree->depth = depth;
	tree->root = root;

	return tree;
}

int find_depth(TreeNode * root,int count)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return count;
	}


	count++;

	int countl = find_depth(root->left,count);
	int countr = find_depth(root->right,count);

	if(countl > countr )
	{
		return countl;
	}
	else
	{
		return countr;
	}

	
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


TreeNode * assign_parent(TreeNode *root,TreeNode *parent)
{
	if(root == NULL)
	{
		return NULL;
	}

	root->parent = parent;
	root->left = assign_parent(root->left,root);
	root->right = assign_parent(root->right,root);

	return root;
}

bool search(TreeNode *root,int value, int*arr,int *i)
{
	int j = 0;
	if(root == NULL)
	{
		return false;
	}
	if(root->value == value)
	{
		while(root->parent != NULL)
		{
			arr[j] = root->value;
			j++; 
			root = root->parent;
		}
		*i = j;
		return true;
	}

	if(search(root->left,value,arr,i) || search(root->right,value,arr,i) )
	{
		return true;
	}
	else
	{
		return false;
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


#if !defined(GRADE_BUILD) && !defined(GRADE_PRINT)
void free_tree(Tree *tree)
{
	// Use recursion. Be careful to not access a memory location after
	// freeing it. Use Valgrind extensively to test this function out.
	// Always debug the first Valgrind error before any other. Pay
	// attention to your memory leaks. You should create a helper
	// function that is recursive and have this function call it.

	TreeNode *root = tree->root;
	free_allNodes(root);
	free(tree);
	return;

}
#endif

#if !defined(GRADE_FREE) && !defined(GRADE_PRINT)
Tree *build_tree_from_files(char const *preOrderFile, char const *inOrderFile)
{
	// This function is the meat of the assignment really. Be careful, it's
	// gonna get big quick. You need to split up functionality in several
	// helper functions to maintain your sanity. To verify that the function
	// works properly, you should be writing thorough unit tests. However,
	// at the beginning, you'll want to rely on GDB. Spend some time getting
	// comfortable navigating complex data structures (such as binary trees)
	// using GDB. It's a very useful skill. Anyways, remember that this is
	// engineering: split the problem up into manageable, smaller problems,
	// and tackle each one one by one.

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
	int depth = 0;
	TreeNode *root = insert_treenodes(in_order, start, end,pre_order,pre_index,count);
	root = assign_parent(root,NULL);
	depth = find_depth(root,depth);
	Tree *tree = alloc_tree(count,depth,root);

	free(in_order);
	free(pre_order);
	fclose(input1);
	fclose(input2);

	return tree;

}
#endif

#if !defined(GRADE_FREE) && !defined(GRADE_BUILD)
void print_path_from_root_to_node(Tree *tree, int value)
{
	// Figuring out how to print the path in the correct order is the
	// challenge here. I suggest making use of the parent attribute
	// added to the tree node structure in tree.h. Again, just assume
	// that the parent attribute stores the address of the parent node in
	// the tree. Feel free to use another method to print the path if you
	// wish.

	TreeNode *root = tree->root;
	int *arr = calloc(tree->numNodes,sizeof(int));
	int i;
	if(search(root, value, arr,&i))
	{
		printf("%d ",root->value);
		for(int j = i-1;j>= 0;j--)
		{
			printf("-> %d ",arr[j]);
		}
		printf("\n");
	}
	free(arr);
	return;


}
#endif
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
///////////////////////////////////////////////////////////////////////////////
