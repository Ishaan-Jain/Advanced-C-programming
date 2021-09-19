#include <stdio.h>
#include <stdlib.h>

#include "freq.h"
#include "list.h"
#include "tree.h"
#include "huffman.h"

int main()
{
	FreqEntry *freqArray = calculate_frequencies("input/file1.txt");
	Node *huffList = build_huffman_list(freqArray);
	TreeNode *huffTree = build_huffman_tree(huffList);
	return EXIT_SUCCESS;
}
