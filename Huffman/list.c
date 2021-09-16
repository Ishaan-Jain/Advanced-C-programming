#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "list.h"

Node *alloc_node(TreeNode *treeNode)
{
	Node *node = malloc(sizeof(Node));
	if(node == NULL) {
		fprintf(stderr, "[ERROR] malloc() failed.\n");
		exit(EXIT_FAILURE);
	}

	node->huffTree = treeNode;
	node->next = NULL;
	return node;
}

void free_node(Node *node)
{
	free(node);
}

/*void print_list(Node *head)
{
	Node *ptr = head;
	while(ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}*/

Node *insert_node(Node *head, Node *node)
{
	node->next = head;
	return node;
}

/*Node *delete_node(Node *head, Node *node)
{

	if(head == node) {
		Node *temp = node->next;
		node->next = NULL;
		return temp;
	}

	Node *ptr = head;
	while(ptr != NULL) {
		
		if(ptr->next == node) {
			ptr->next = node->next;
			break;
		}

		ptr = ptr->next;
	}

	node->next = NULL;
	return head;
}*/

/*Node *search_node(Node *head, int data)
{
	Node *ptr = head;
	while(ptr != NULL) {
		if(ptr->data == data) {
			return ptr;
		}
		ptr = ptr->next;
	}

	return NULL;
}*/
