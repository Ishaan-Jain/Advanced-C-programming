////////////////////////////////////////////////////////////////////////////////
///                                  list.h                                  ///
////////////////////////////////////////////////////////////////////////////////
#ifndef __LIST_H__
#define __LIST_H__

typedef struct node {
	int value;
	struct node *next;
} Node;

/*
 * alloc_node()
 *
 * Allocated memory for a linked list node on the heap and initialize its value
 * attribute. Returns the address of the node on success, returns NULL on 
 * failure. Leaks the number of bytes required for one node.
 */
Node *alloc_node(int value);

/*
 * free_node()
 *
 * Free the heap memory allocated for a node. Does not leak any memory at all.
 */
void free_node(Node *node);

/*
 * free_list()
 *
 * Free all nodes in a linked list. Does not leak any memory at all.
 */
void free_list(Node *head);

/*
 * print_list()
 *
 * Prints the values in a linked list in the order they appear starting from
 * the head of the list. Does not free the list at head. Does not leak any
 * additional memory.
 */
void print_list(Node *head);

/*
 * insert_node_at_head()
 *
 * Insert a node at the head of a linked list. Return the head of the list.
 */
Node *insert_node_at_head(Node *head, Node *node);

/*
 * insert_node_at_tail()
 *
 * Insert a node at the tail of a linked list. Return the head of the list.
 * Does not free the list at head or the node. Does not leak any additional
 * memory.
 */
Node *insert_node_at_tail(Node *head, Node *node);

/*
 * get_list_length()
 *
 * Returns the number of nodes in a linked list. Does not free the list at head.
 * Does not leak any additional memory.
 */
int get_list_length(Node *head);

#endif // __LIST_H__
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
