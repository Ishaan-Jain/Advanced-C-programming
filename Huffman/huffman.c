#include <stdlib.h>

#include "list.h"
#include "huffman.h"
#include "freq.h"

Node *build_huffman_list(FreqEntry *freqArray)
{
	Node *huffList = NULL;

	for(int i = 0; i < FREQ_SIZE; i++) {
		// Only work with characters with non-zero frequencies.
		if(freqArray[i].freq > 0) {
			// Build TreeNode for the characters.
			TreeNode *chNode = alloc_tree_node(freqArray[i].ch, freqArray[i].freq);
			// Build the list node for the characters tree node.
			Node *node = alloc_node(chNode);
			// Insert the list node into the huffman list.
			huffList = insert_node(huffList, node);
		}
	}

	// huffList will be sorted in descending order by frequency.
	return huffList;
}
