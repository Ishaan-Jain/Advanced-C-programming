#ifndef __LIST_H__
#define __LIST_H__

/**
 * The structure representing one node in the linked list. The linked list
 * itself must be a doubly linked, circular list!
 */
typedef struct node {
	int value;
	struct node *prev;
	struct node *next;
} Node;

/**
 * Allocate the memory on the heap for one node. Initialize the node's value and
 * make it point to itself. If the allocation fails, return NULL.
 */
Node *alloc_node(int value);

/**
 * Count the number of nodes in a linked list. If 'head' is NULL, the list is
 * empty.
 */
int get_length(Node *head);

/**
 * Print the values of the linked list in the order of the linked list.
 */
void print_list(Node *head);

/**
 * Insert a new node at the head of the list. Return the address of the head of
 * the linked list. Assume 'newNode' is a valid address of a node on the heap.
 */
Node *push_node(Node *head, Node *newNode);

/**
 * Remove the head node of the linked list. Return the address of the removed
 * node. If 'head' is NULL, do nothing.
 */
Node *pop_node(Node *head);

/**
 * Search a node by value in the linked list. Return the address of the node if
 * found, return NULL otherwise.
 */
Node *search_node(Node *head, int value);

/**
 * Remove the nth node from a linked list. If 'n' not between one and the number
 * of nodes in the linked list (inclusive), do nothing.
 */
Node *remove_nth_node(Node *head, int n);

#endif
