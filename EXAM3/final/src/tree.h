////////////////////////////////////////////////////////////////////////////////
///                                  tree.h                                  ///
////////////////////////////////////////////////////////////////////////////////
#ifndef __TREE_H__
#define __TREE_H__

/**
 * The binary tree node structure you are using here. No suprises.
 */
typedef struct treenode {
	int value;
	struct treenode *left;
	struct treenode *right;
} TreeNode;

TreeNode *alloc_tree_node(int value);
void free_tree_node(TreeNode *node);
int find_highest_path_weight(TreeNode * root,int count);\
TreeNode *build_tree_from_files(char const *preOrderFile, char const *inOrderFile);
TreeNode *insert_treenodes(int *in_order,int start, int end,int *pre_order,int pre_index,int count);

TreeNode *insert_treenodes(int *in_order,int start, int end,int *pre_order,int pre_index,int count);

int number_siblings(TreeNode *root, int count);
void free_allNodes(TreeNode *root);

/**
 * Compute the highest path weight in the input tree and return that value. If
 * the tree is empty, return 0.
 */
int get_highest_path_weight(TreeNode *root);

/**
 * Count the number of sibling pairs in the input tree and return that value. If
 * the tree is empty, return 0.
 */
int count_siblings(TreeNode *root); 

#endif
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
