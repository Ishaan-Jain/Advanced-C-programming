# Programming Assignment VIII

*Last modified: 07/26/2021 at 1:45PM*

## Goals

* You will learn how to build and work with binary trees in C,

* You will learn how to use recursion to navigate binary trees,

* You will learn how to manage writing complex functions that require many steps.

## Structure

* `src`: Your code will need to be written in tree.c. Declarations and specification comments can be found in tree.h. I also added some helpful comments in tree.c itself.
* `tests`: Only `acutest.h` is provided and some input trees. You **will** need to create more trees to truly test your code.

For this assignment, I suggest that you write a main.c file as well in the src directory that calls your functions such as to create a full program that makes sense. For example, you could open with a call to `build_tree_from_files` to build the tree, then call `print_path_from_root_to_node` on several nodes, and finally call `free_tree`. This could help you get a better grasp on what each function is supposed to be doing.

## Background

### Binary Trees

This assignment has you implementing a simple binary tree, no different than the one discussed in lecture. Writing code for a modified tree would not be very different anyways. Note that we are not working with binary search trees, but only binary trees (thus there is no requirement that one node be to one particular side of another).

### Tree Traversals

Unlike linear data structures (array, linked list, etc) which have only one logical way to traverse them, trees can be traversed in different ways.
For more information, see [the Wikipedia page on tree traversal](https://en.wikipedia.org/wiki/Tree_traversal). You will want to build a strong
understanding of tree traversal before you tackle this assignment. I suggest you start with pen and paper and a few toy tree examples.

The first part of this assignment, and the biggest part, consist of constructing a binary tree based on its pre-order and in-order traversals. We assume that the 
binary tree contains no duplicate values, and thus, that the tree is uniquely determined by its two traversals (note that only one of those two is not sufficient to uniequely determine the tree. Make sure you understand why).
As an example, consider the following traversals, displayed as arrays here:

* Pre-order traversal: [1, 2, 4, 3]
* In-order traversal: [2, 1, 3, 4]

Then, the only binary tree that possesses the given traversals is

```
  1
 / \
2   4
   /
  3
```

Write more examples, translate them into unit tests, and use them to write and debug your code. You will find two pair of input files in the tests/input directory. The files use the same format as in PA03 and PA06: just one integer per line. In your functions, simply assume that the input files are formatted correctly. Not need to worry about bad inputs. Focus on the tree traversal aspects.

### Print Path from the Root to the Node

The second portion of this assignment consist of implementing a function that prints out the path from the root of a binary tree to one of its nodes
to the console. The path should be printed with the following format:
```
<root> -> <node 1> -> <node 2> -> [... ->] <target node> 
```

For example, in the binary tree shown above, the path from the root to node with value 3 should be
```
1 -> 4 -> 3
```
The number and placement of white-spaces (exclusing new-lines) is not important. However, there must be exactly one arroa `->` to represent a link. There must be a new-line at the end of the path.

## Requirements

As with the previous two programming assignments, I have decided to insert the specifications for each function you have to implement right above the function declarations in tree.h as comments. Make sure you abide by those specifications. Note that only three functions are being graded. All other functions declared in tree.h are suggestions to you. Feel free to modify their specifications and/or declarations.

| Function | Inputs | 
|---|---|
|`free_tree`| - `Tree *tree`: A pointer to the tree wrapper that contains the tree to be freed by the function. |
| `build_tree_from_files` | - `char const *preOrderFile`: The input file that contains the pre-order traversal sequence for the binary tree. <br>- `char const *inOrderFile`: The input file that contains the in-order traversal sequence for the binary tree. |
| `print_path_from_root_to_node` | - `Tree *tree`: A pointer to a binary tree. <br>- `int value`: A value that might correspond to a node in `tree`, which will be the target node. |

*Hint: you definitely want to be using recursion somewhere in each function. This will involve creating helper functions that are themselves recursive. Remember to keep your functions small, and come up with a hierarchical order to you function calls. This will simplify the debugging task, and make receiving help from a TA most expeditive.*

## Submission

Navigate to the src directory where your `tree.c` file is, and compress it with:

```
zip tree.zip tree.c
```

Then, upload the zip file to Brightspace in the appropriate submission box.
