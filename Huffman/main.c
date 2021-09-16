#include <stdio.h>
#include <stdio.h>

#include "freq.h"
#include "list.h"
#include "tree.h"
#include "huffman.h"

int main()
{
	FreqEntry *freqArray = calculate_frequencies("input/file1.txt");
	Node *huffList = build_huffman_list(freqArray);

	Node *ptr = huffList;
	while (ptr != NULL) {
		printf("%c: %d\n", (char) ptr->huffTree->ch, ptr->huffTree->freq);
		ptr = ptr->next;
	}
}
