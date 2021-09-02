# Programming Assignment VII

*Last modified: 07/18/2021 at 3:30PM*

## Goals

The goals of this assignments are:

* To implement a linked list library style,

* To use linked list to solve a computational problem.

## Structure

The structure of the code for this assignment is as follows:

* `src`: You must write your code for the required functions in two files: cake.c and list.c. The declarations for these functions, as well as their documentation, can be found in the corresponding header files: cake.h and list.h. As always, there is a main.c file present for quick and dirty testing. Note that the documentation for the functions to be implemented in list.c and cake.c appears in list.h and cake.h, respectively. This is standard practice: one would rather not have to look at implementation details to learn how to use a library. Instead, one would rather only deal with the header files.

* `tests`: Only acutest.h is provided. You will need to build your unit test suite from the ground up using the framework. Spend the time to make these tests good. This is an extremely important ability for a programmer, especially a code library programmer, since libraries are typically used by a large number of people.

## Background

### Linked Lists

This assignment focuses on linked lists. You essentially have two tasks. The first is for you to write a linked list implementation in the files list.h and list.c. The implementation portion (i.e. the code that actually implements the functionality for the linked list) should be written in list.c. The interface portion (i.e. the code that describes the interface with your implementation) is already written in list.h and should not be changed. The second task is for you to use your linked list implementation, through its interface, to solve a simple computational problem called "Who gets the cake?". Lectures 21, 22, and 23 form the core set of lectures you will need to complete this assignment.

Remember that we use NULL (set to address 0x0) to represent the end of a linked list in this implementation. Also, a head pointer equal to NULL simply means that the linked list is empty.

### Who Gets the Cake

Imagine that there is a piece of cake and several people want it. They decide who can have it by playing a game. The players form a circle and choose an integer k greater than one, referred to as the interval. They designate one player as the starting player, and count from 1 to k, and the k-th player is eliminated from the circle. They count again k players and the k-th one is eliminated. They repeat this process until only one player is left, whom is then declared the winner and gets the cake. In the following example, there are 6 players, and they have chosen the interval k to be 3.

1. Initialize a list counting from 0 to 5:
    ```
    0 -> 1 -> 2 -> 3 -> 4 -> 5
    ```
2. Count to the k-th player, remove that player from the list. In this case, player 2 is the 3rd player, so he is eliminated and removed from the list:

    ```
    0 -> 1 -> 2 -> 3 -> 4 -> 5
              ^
    ```

3. Count to the k-th player again. In this case, player 5 is eliminated:

    ```
    0 -> 1 -> 3 -> 4 -> 5
                        ^
    ```

4. Now that we reached the end of the list, we go back to the beginning of the list, and count from 1 to k again. This time, player 3 is eliminated:

    ```
    0 -> 1 -> 3 -> 4
              ^
    ```

5. Next, player 1 is eliminated:

    ```
    0 -> 1 -> 4
         ^
    ```

6. Next, player 4 is eliminated:

    ```
    0 -> 4
         ^
    ```

7. In the end, the player 0 is left and wins the game:

    ```
    0
    ```

## Requirements

First, implement the following five functions for the linked list library:

| Function | Input | Output/Effect |
|---|---|---|
| `insert_node_at_head()` | - `Node *head`: pointer to the head node of a list. <br>- `Node *node`: pointer to the list node to be inserted. | See list.h. |
| `insert_node_at_tail()` | - `ListNode *head`: pointer to the head node of a list. <br>- `Node *node`: pointer to a list node to be inserted. | See list.h. |
| `get_list_length()` | - `Node *head`: pointer to the head node of a list. | See list.h. |
| `free_list()` | - `Node *head`: pointer to the head node of a list. | See list.h. |

Then, implement the following two functions for the "Who gets the cake?" game logic:

| Function | Input | Output/Effect |
|---|---|---|
| `create_list()` | - `int numPlayers`: Number of players in the game. | See cake.h. |
| `eliminate()` | - `int numPlayers`: Number of players in the game. <br>- `int interval`: k | See cake.h. |

## Compiling and Linking

Adapt a Makefile from a previous assignment. Make sure that you are using `-Wall -Wextra -Werror -Wvla` when compiling your code (minus `-Wvla` when compiling unit tests). If you define any helper functions, include their definitions and declarations inside of the source files, not header files, since you are not turning those in.

## Testing your code

You will need to write a comprehensive unit testing suite for your code inside of the tests directory using the acutest.h framework.

## Submission

Navigate to the src directory where your `list.c` and `cake.c` files are, and compress them with:

```
zip pa07.zip list.c cake.c
```

Then, upload the zip file to Brightspace in the appropriate submission box.
