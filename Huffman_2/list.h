#ifndef __LIST_H__
#define __LIST_H__

#include "tree.h"

typedef struct node {
	TreeNode *huffTree;
	struct node *next;
} Node;

Node *alloc_node(TreeNode *huffTree); // Constructor (not the same as in C++)
void free_node(Node *node);

//void print_list(Node *head);

Node *sorted_insert_node(Node *head, Node *node);
//Node *remove_node(Node *head, Node *node);
//Node *search_node(Node *head, int data);

#endif
