#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include "list.h"
#include "freq.h"

Node *build_huffman_list(FreqEntry *freqArray);

#endif
