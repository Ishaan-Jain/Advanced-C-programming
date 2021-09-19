#include <stdlib.h>

#include "list.h"
#include "huffman.h"
#include "freq.h"
#include "tree.h"

Node *build_huffman_list(FreqEntry *freqArray)
{
	Node *huffList = NULL;

	for(int i = 0; i < FREQ_SIZE; i++) {
		if(freqArray[i].freq > 0) {
			TreeNode *chNode = alloc_tree_node(freqArray[i].ch, freqArray[i].freq);
			Node *node = alloc_node(chNode);
			huffList = sorted_insert_node(huffList, node);
		}
	}

	return huffList;
}

TreeNode *build_huffman_tree(Node *huffList)
{
	while(huffList != NULL && huffList->next != NULL) {
		// Save pointers to first three nodes in list.
		Node *first = huffList;
		Node *second = huffList->next;

		// Remove the first two, which are the least frequent characters.
		huffList = remove_node(huffList, first);
		huffList = remove_node(huffList, second);

		// Save the addresses of the tree nodes, then free the nodes.
		TreeNode *t_first = first->huffTree;
		TreeNode *t_second = second->huffTree;
		free_node(first);
		free_node(second);

		// Combine the two least frequent characters.
		TreeNode *combined = merge_tree(t_first, t_second);

		// Insert the combination back into the linked list in sorted order.
		Node *newNode = alloc_node(combined);
		huffList = sorted_insert_node(huffList, newNode);
	}

	TreeNode *finalHuffTree = huffList->huffTree;
	free_node(huffList);
	return finalHuffTree;
}

TreeNode *merge_tree(TreeNode *first, TreeNode *second)
{
	TreeNode *combined = alloc_tree_node('\0', first->freq + second->freq);

	combined->left = first;
	combined->right = second;

	return combined;
}
