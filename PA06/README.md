# Programming Assignment V

*Last modified: 07/14 at 11:30PM*

## Goals

The goals of this assignments are:

* To become proficient at writing and debugging programs that use recursion.

## Structure

The structure of the code for this assignment is as follows:

* `src`: merge.c contains the four functions you need to implement for this programming assignment. merge.h contains the declarations and should not be changed. If you defined a helper function, put a declaration for it at the top of the merge.c file, not inside of merge.h (this is just because we need to be able to compile your code with your merge.c file submission only).

* `tests`: acutest.h, the unit testing framework, and four empty test source files to fill out.

As you are surely noticing, the template directory structure for the programming assignments is becoming increasingly barren. This is a natural development. You simply want to look at what previous assignments did and adapt it.

## Background

This programming assignment focuses on the technique of recursion. You will be implementing a recursive version of merge sort.

Merge sort is one of many sorting algorithm that easily lends itself to recursion. There will be a lecture covering the conceptual understanding of merge sort.

## Requirements

Two of the functions you must implement, `read_data()` and `write_data()` are extremely similar to those your wrote for PA03. In fact, the input/output file formats are exactly the same. Naturally, they will not carry much weight in your overall grade for this assignment.

Merge sort will be implemented in two functions: `merge()` and `merge_sort()`. `merge_sort()` is the recursive one.

| Function      | Input                                                        | Output/Effect                                                |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `read_data()`  | - `char const *filename`: path to an input file. <br>- `int **arr`: pointer to an `int *` quantity (an array here) that will hold the integers read from the input file. <br>- `int *size`: pointer to an `int` that will hold the number of the integers being read. | See the comments in merge.c. |
| `write_data()` | - `char const *filename`: path to an output file. <br />- `int const *arr`: an integer array that will be written to `filename`<br />- `int size`: the size of `arr` | See the comment in merge.c. |
| `merge()`     | - `int *arr`: an integer array<br />- `int l`: start index of the first sorted region (inclusive) <br />- `int m`: start index of the second sorted region (inclusive) <br />- `int r`: end index of the second sorted region (exclusive) | See the comment in merge.c. |
| `merge_sort()` | - `int *arr`: an integer array<br />- `int l`: the start index of the region to be sorted (inclusive)<br />- `int r`: the end index of the region to be sorted (exclusive) | See the comment in merge.c.        |


## Compiling and Linking

Adapt a Makefile from a previous assignment to this one. Make sure to compile with the appropriate warning and error flags.

## Testing your code

As always, you should write comprehensive unit tests for your function under the tests directory.

## Submission

Navigate to the src directory where your `merge.c` file is, and compress it with:

```
zip merge.zip merge.c
```

Then, upload the zip file to Brightspace in the appropriate submission box.
