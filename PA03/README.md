# Programming Assignment III

*Last modified: 06/29/2021 at 9:47AM*

Corrected an error in the Makefile.

## Goals

* To learn the basics of file I/O in C,

* To learn how to use `qsort`,

* To learn how to create good unit tests.


## Code Structure

* `src`: contains three files. The file qsort.h contains the declarations for the five functions you must implement. You do not need to modify this file. The file qsort.c is the file you need to complete with working definitions for the five functions you are required to implement. The file main.c is available for quick and dirty testing purposes. It contains some code already which provide an example of how the five functions could be called in sequence to form a complete program that counts, reads, sorts and writes integers.

* `tests`: contains acutest.h, five unit testing files, and the input and expected output directories. You will need to write unit testing code within the five .c test files.

* We have also decided to provide the Makefile for this assignment to alleviate some of the pressure.

## Background

To complete this assignment, you will need to know how to open, manipulate, read from, write to, and close files in C. Moreover, you will need to know how to use the `qsort` sorting function available through the standard library. Start by opening the manual page for `qsort`:
```
man qsort
```
Reading the function synopsis and description alone may not be enough to give you the understanding you need to use `qsort`. In essence, `qsort` does the job of sorting the elements of the array for you. All you need to tell `qsort` is the rule to sort two arbitrary elements, and it does the rest for you (you can convince yourself mathematically that this is sufficient information to sort the whole array). This rule is provided to `qsort` in the form of a comparison function (called `compare_int` in this assignment) with two arguments. `qsort` will call this comparison function as many times as it needs to figure out the final sorted order. By design, `qsort` will expect the comparison function to return a negative value if its first argument should be sorted before the second in the final array, and a positive value otherwise. It should return zero if the order does not matter (if both arguments point to the same value for example). You should find more examples online if needed.

## Requirements

There are five functions you are required to implement in this assignment:

| Function       | Input                                                                                                                                                                                                                         | Output / Effect                                                                                                                                                                                                                                                                                                                                                                    |
|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `count_int_from_file`   | `FILE *stream` points to a file stream assumed to be open for reading. The file pointed to follows the format specified in the next section.                                                                                                                                                                                   | Count the total number of integers in the file pointed to by `stream` and return the count. If the input file contains `124\n 378\n -56\n`, this function should count and return 3. Do not count individual digits '1', '2', '4', etc. This function must have no side effect (Hint: you must preserve file cursor position, error flags, etc. if you think they might be affected by this function)! If this function encounters any error, it should return `COUNT_FAIL` (defined in qsort.h).                                                                                                                                                                                                                                                                                 |
| `read_int_from_file`    | - `FILE *stream` points to a file stream assumed to be open for reading. The file pointed to follows the format specified in the next section. <br /> - `int *buffer` is an array of integers allocated by the caller. <br /> - `int size` is the size of `buffer`.                                                                                     | Read as many integers as possible up to `size` from the input file, one at a time, into `buffer`. Start reading from the current cursor position. `buffer` should be filled starting with `buffer[0]` and onwards. Return the number of integers read. Return `READ_FAIL` if an error occurred while handling the input file. The file cursor position should end up right after the last integer read (which could be the end of the file).                                                                                                                                                                        |
| `compare_int` | `const void *first` and `const void *second` are pointers to two integersto be compared. They are of type `const void *` because this is required by `qsort`. | This is a comparison function to make `qsort` sort the integers in ascending order. This means: <br /> * Return <0 if integer pointed to by `first` is smaller than that pointed to by `second` <br /> * Return 0 if integer pointed to by `first` is equal to that pointed to by `second` <br /> * Return >0 otherwise. <br /> See [this page](https://linux.die.net/man/3/qsort) for more information on the semantics of the comparison function. |
| `write_int_to_file`   | - `FILE *stream` points to a file stream assumed to be open for writing. The file should be written following the format specified in the next section. <br /> - `int *buffer` is the array of integers to be written to the output file stream. <br /> - `int size` is the size of `buffer` (i.e. number of elements).                                          | Write `size` integers from `buffer` into the output file pointed to by `stream`. The integers should be appended to the file; that is, they should be written after the last integer already in the output file, with at least one white-space character of separation. The function should return the number of integers written to the output file. If, for some reason, the function encounters an error while handling the output file, it should return `WRITE_FAIL`.                                                                                                                                                                                                                                                                             |
| `sort_int_with_qsort`       | - `int *buffer` is an integer array to be sorted. <br /> - `int size` is the size of `buffer`.                                                                                                  | Sort the integers in `buffer` in ascending order using qsort. Your qsort call should be using the `compare_int` function.                                                                                                                                                                                                                                                                                                                         |

## File Format

The input and output files used for reading and writing should be formatted as follows: exactly one integer per line. A given line may contain any number of white-space characters (e.g. spaces, new-lines, tabs, etc.). Your function may assume that the input files are correctly formatted. An example of a valid input file is
```
3
1
2
```
Or,
```
 3
    4
1
```
Assume input files have no more than 100 lines (integers).


## Compiling and Linking

The Makefile is provided. You can run
```
make debug
```
to compile and link all of your code from src (including main.c) into build/debug. You can use
```
make run-debug
```
to do the same but also run the executable. Note that if your program expects inputs through `argv` (as the template main.c does), you'll need to navigate to the bottom of the Makefile and add the arguments in the appropriate location in the run-debug recipe. Alternatively, you may simply use the command line directly CS 159 style. 

If you decide to compile directly without using the Makefile, make sure the compilation command uses `-Wall -Wextra -Wvla -Werror`. If you are compiling a unit test, remove `-Wvla` because acutest uses it. Once again, we are using these flags to compile your code for grading. If we cannot compiler your code, and it is not a problem on our end, you will receive a zero.

## Testing Your Code

*See June 29th lecture for additional material.*

There is a unit testing file for each function to be implemented:

* `test_count_int.c`

* `test_read_int.c`

* `test_compare_int.c`

* `test_write_int.c`

* `test_sort_int.c`

They are all initially empty and should be filled with your unit tests. To run a given unit test, you can use
```
make run-test-count-int
```
See the bottom of the Makefile for the other targets. Note that we have provided some input and expected files within the tests directory.

## Submission

Navigate to the `src` directory where you `qsort.c` file is, and compress it with:

```
zip qsort.zip qsort.c
```

Then, upload the zip file to Brightspace in the appropriate submission box.
