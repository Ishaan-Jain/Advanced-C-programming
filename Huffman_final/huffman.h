#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include "list.h"
#include "freq.h"
#include "tree.h"

Node *build_huffman_list(FreqEntry *freqArray);
TreeNode *build_huffman_tree(Node *huffList);
TreeNode *merge_tree(TreeNode *first, TreeNode *second);

#endif
