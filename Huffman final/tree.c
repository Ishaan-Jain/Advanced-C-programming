#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

TreeNode *alloc_tree_node(int ch, int freq)
{
	TreeNode *node = malloc(sizeof(TreeNode));
	if(node == NULL) exit(EXIT_FAILURE);

	node->ch = ch;
	node->freq = freq;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void free_tree_node(TreeNode *node)
{
	free(node);
}

/*void print_tree(TreeNode *root)
{
	if(root == NULL) {
		return;
	}

	// Go to the left, make a recrusive call on the left sub-tree.
	print_tree(root->left);
	
	printf("%d\n", root->data);

	// Same thing on the right.
	print_tree(root->right);
}*/

/*TreeNode *insert_tree_node(TreeNode *root, TreeNode *node)
{
	if(root == NULL) {
		return node;
	}

	if(node->data < root->data) {
		root->left = insert_node(root->left, node);
		return root;
	}

	else {
		root->right = insert_node(root->right, node);
		return root;
	}
}*/

/*bool search_node(TreeNode *root, int data)
{
	if(root == NULL) {
		return false;
	}
	
	if(root->data == data) {
		return true;
	}

	if(data < root->data) {
		return search_node(root->left, data);
	}

	else {
		return search_node(root->right, data);
	}
}*/

/*TreeNode *remove_node(TreeNode *root, int data)
{
	if(root == NULL) {
		return NULL;
	}

	if(root->data == data) {
		if(root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
	}

	if(data < root->left) {
		root->left = remove_node(root->left, data);
		return root;
	}

	else {
		root->right = remove_node(root->right, data);
		return root;
	}
}*/
