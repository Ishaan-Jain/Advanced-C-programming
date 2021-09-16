#ifndef __TREE_H__
#define __TREE_H__

#include <stdbool.h>

typedef struct treenode {
	int ch;
	int freq;
	struct treenode *left;
	struct treenode *right;
} TreeNode;

TreeNode *alloc_tree_node(int ch, int freq);
void free_tree_node(TreeNode *node);

//void print_tree(TreeNode *root);

TreeNode *insert_tree_node(TreeNode *root, TreeNode *node);
//TreeNode *remove_node(TreeNode *root, int data);
//bool search_node(TreeNode *root, int data);

#endif
