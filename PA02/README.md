# Programming Assignment II

*Last modified: 06/18/2021 at 12:25PM*

## Setup

Follow the instructions provided at the beginning of PA01's README.md file to setup this assignment on your ecegrid machine. As always, be sure to keep up to date with any changes.

## Goals

The goals of this assignment are:

* To reinforce concepts related to number bases,
* To teach you how to write programs that handle numbers and characters,
* To get you familiar with the use of build systems (Make) and debuggers (GDB),
* To introduce you to the concept of test-driven-development (TDD).

## Structure

The structure of the code for this assignment is as follows:

* `src`: This directory contains the source code. The file `convert.c` is almost complete, but contains **several** bugs, and the code is not functional. You tasks are to read through this file, thoroughly understand what the code is trying to do, and then, use a combination of appropriate unit tests and GDB (the debugger) to find the bugs and correct them, until the code is functional according to the specifications provided below.
* `tests`: This directory contains the unit testing code. The existing test functions are empty, and you'll want to fill them in with test cases in order to, firstly, reveal the bugs, and secondly, verify that the code is correct.
* No `Makefile` is provided for this assignment! You should download the Makefile template from Brightspace and customize it for this assignment.

## Background

The radix or base is the number of unique digits, including the digit zero, used to represent numbers. For example, for the decimal/denary system (the most common system in use today) the radix (base number) is ten, because it uses the ten digits from 0 through 9. For values stored in a computer, the radix is two, because a digit can only take one of two values: 1 or 0, depending on whether the electrical signal is high or low. Watch the lecture on number bases and visit [the Wikipage on radix](https://en.wikipedia.org/wiki/Radix) to refresh your knowledge on how it all works.

You will need to write your own Makefile for this assignment, you will need to debug your code using GDB, and you will write your own unit tests using the acutest framework. Make sure to watch the appropriate lectures before starting.

## Requirements

There are three functions that you have to debug.

### Convert character to number

#### Declaration

`int convert_char_to_num(char c);`

#### Description

This function converts a given character into the base ten number that it represents.

#### Arguments

The characters `c` must be either a digit (i.e. '0' through '9') or a lower case letter (i.e. 'a' through 'z'). If the character is invalid, the function should return the value -1 to indicate failure.

#### Return Value

The function returns the integer base ten value that corresponds to the input character.

#### Examples

```c
convert_char_to_num('0');     // This should return integer 0
convert_char_to_num('9');     // This should return integer 9
convert_char_to_num('a');     // This should return integer 10
convert_char_to_num('z');     // This should return integer 35
convert_char_to_num('A');     // This should return integer -1, since upper case letters are not valid
```

### Convert number to character

#### Declaration

`char convert_num_to_char(int n);`

#### Description

This function converts a given base ten number into the character that represents it.

#### Arguments

The integer `n` must be a value between 0 and 35. Otherwise, the function should return the value 0 (not character '0') to indicate failure.

#### Return Value

The function returns a character that represents the base ten number `n` provided as input, or the value 0 if the input number is invalid.

#### Examples

```c
convert_num_to_char(0);       // This should return character '0'
convert_num_to_char(9);       // This should return character '9'
convert_num_to_char(10);      // This should return character 'a'
convert_num_to_char(35);      // This should return character 'z'
convert_num_to_char(50);      // This should return 0.
```

### Convert base

#### Declaration

`void convert_base(char * numStrRep, int inputBase, int outputBase);`

#### Description

This function converts a number from one base to another, and prints the converted number to `stdout` with a trailing newline character.

#### Arguments

* `numStrRep`: the string representation of the number to be converted (e.g. "a10b", "333", etc.).
* `inputBase`: the base of the input number, assumed to be between 2 and 36.
* `outputBase`: the base to which the input number is to be converted, assumed to be between 2 and 36.

#### Return Value

This function has no return value, and instead prints the converted number to `stdout`. If any failure occurred while converting the number, however, the program is aborted (i.e. `exit()` is called).

#### Examples

```c
convert_base("5", 10, 16);       // This should print "5"
convert_base("5", 10, 2);        // This should print "101"
convert_base("1111", 2, 10);     // This should print "15"
convert_base("1234", 2, 10);     // The program should print nothing and return, since 1234 is not a valid base-2 number
```

## Compiling and Linking

Unlike PA01, we do not provide the complete `Makefile` to compile and execute your code.
You should adapt the `Makefile` template on Brightspace to this assignment and use it to compile and run your code, as was done in PA01.
Make sure that you are compiling with all of the suggested warning flags, as they may help in revealing some of the bugs.

## How do I get started?

1. Your first step should be the thoroughly read through the provided code, especially that inside of the **convert.c** file.
2. You should download the template Makefile from Brightspace and adapt it. Running the unit tests for a function should require you to run only a single make command.
3. Select a function (preferrably not `convert_base` to start with since it depends on the others) to debug first.
4. Write a set of unit tests.
5. Run the unit tests and debug them.
6. Go back through step 4 and 5 until you have fully debugged the function, then move on to the next function.

## Testing Your Code

As expected, there is one unit test file per required function.

* `test_char_to_num.c`

* `test_num_to_char.c`

* `test_convert_base.c`

Each file has empty test functions within it. You should fill in these functions with appropriate `TEST_CHECK` and `TEST_MSG` calls that test what the function name claims to test. Your unit tests should be thorough and give you confidence that the functions inside **src/convert.c** are correctly implemented.

For the `convert_base` function, because the output to be tested is printed to `stdout`, we cannot write a unit test using `TEST_CHECK` without first redirecting `stdout`. We have provided the macro `TEST_STDOUT_EQUALS` that you can use to compare your function's output to `stdout` against a string. An example usage of this macro is given in **tests/test_convert_base.c**.

## How this assignment will be graded

Within each test file there are multiple test functions, each covering a specific test case that is summarized by the name of that function.
To grade your work, we will use these test functions exactly, except that we will fill them with our own TEST_CHECK calls to implement them.
**We are not relying on your implementations for the test functions. We will be using our own implementations.**
Each test function is worth 10 points.
Across all unit test files, there are 10 test functions, summing up to 100 points.

For example, in `test_char_to_num.c` there are 3 test functions, each testing a different scenario:

* (10pts) `test_invalid_input()` tests whether `convert_char_to_num()` correctly handles invalid input characters,

* (10pts) `test_0_to_9()` tests whether `convert_char_to_num()` correctly handles characters 0-9,

* (10pts) `test_a_to_z()` tests whether `convert_char_to_num()` correctly handles characters a-z.

Information about what the test function is supposed to test is, exceptionally for this assignment, provided as a comment next to that function in the code.
**To reiterate, we will use the same ten test functions to grade your submission, but their body (implementation) will be our own, not yours.**

## Submission 

Navigate to the `src` directory where your convert.c file is, and compress it with:

```
zip convert.zip convert.c
```

Then, upload the zip file to Brightspace in the appropriate submission box. We are not collecting your Makefile or your unit test files. While it is possible to fully complete this assignment without using Make, unit tests, or GDB, you would miss out on an opportunity to familiarize yourself with these tools, and that would come back to haunt you in later assignments.
