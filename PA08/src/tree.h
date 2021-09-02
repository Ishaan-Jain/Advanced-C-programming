////////////////////////////////////////////////////////////////////////////////
///                                  tree.h                                  ///
////////////////////////////////////////////////////////////////////////////////
#ifndef __TREE_H__
#define __TREE_H__

/**
 * The binary tree node structure you are using in this assignment. The parent
 * attribute has been added for you to use at your discretion.
 */
typedef struct treenode
{
 	int value;
  	struct treenode *left;
  	struct treenode *right;
	struct treenode *parent;
} TreeNode;

/**
 * A tree wrapper structure. It contains the address to the root node of the
 * tree, as well as additional information about the tree that may be useful
 * in certain contexts.
 */
typedef struct tree
{
	int numNodes;		// Number of nodes in the tree.
	int depth;		// Use the definition of depth from lecture,
				// i.e. the maximum number of links from the
				// root node to any of the leaf nodes.
	TreeNode *root;		// The address of the root tree node. The rest
				// of the tree is accessible through the root.
} Tree;

/**
 * Tree nodes will be allocated on the heap. This function allocates a single
 * tree node on the heap, and initializes the value attribute, as well as the
 * children pointers. Return the address of the allocation, or NULL if it
 * failed.
 */
TreeNode *alloc_tree_node(int value);

/**
 * Free the memory associated with a tree node. Assume that the tree node 
 * pointed to was alloacted on the heap.
 */
void free_tree_node(TreeNode *node);

/**
 * Allocate a tree structure on the heap, and initialize its attributes.
 * Return the address of the allocation, or NULL if it fails.
 */
Tree *alloc_tree(int numNodes, int depth, TreeNode *root);

/**
 * Free ALL of the memory allocated for a tree, which includes ALL tree nodes
 * and the tree structure itself. Assume that all memory was allocated on the
 * heap. You should use recursion for this function. This function may take a
 * while to get exactly write (i.e. prevent memory leaks). Make sure you are
 * testing it using Valgrind.
 */
void free_tree(Tree *tree);

/**
 * This function builds a tree in memory based on the content of two files, the
 * first one storing an array of integers representing the pre-order traversal
 * of the tree, and the second one storing an array of integers representing
 * the in-order traversal of the tree. Assume that the tree contains no
 * duplicated integer, and thus, that the tree is uniquely determined by the
 * two traversals. The tree is of course built out of tree nodes, just like
 * what was done in lecture. However, you must also create a tree wrapper around
 * the actual tree, and make sure 'numNodes' and 'depth' are correct. Return
 * the address of the tree wrapper on the heap, or NULL if something failed
 * during the building process.
 */
Tree *build_tree_from_files(char const *preOrderFile, char const *inOrderFile);

/**
 * The function prints the path to stdout from the root node of a tree to the 
 * tree node carrying the specified value. Assume that the tree is valid. If 
 * the path does not exist (e.g. because the value is not in the tree), print 
 * nothing. Traversing the tree to find the target node is trivial, but 
 * printing the desrired path from root to node (and not the reverse) is not.
 * There are several possible solutions. My favorite one involves using the
 * parent attribute I added to the tree node structure. Try to find an elegant
 * solution, as any recursive program should be. Essentially, you should assume
 * that the parent attribute stores the address of the parent tree node.
 */
void print_path_from_root_to_node(Tree *tree, int value);

#endif // __TREE_H__
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
