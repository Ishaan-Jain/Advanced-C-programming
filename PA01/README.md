# Programming Assignment I

*Last modified: 06/05/2021 at 10:36AM*

*Post on Piazza if you have any questions about the following document so that everyone can benefit from our answer. Otherwise, email me or Zhaoning (see syllabus for our email addresses).*

## Setup

### Downloading the code for the first time

To download this assignment onto your ecegrid machine, run:
```
git clone https://github.com/RayaneCTX/ECE264-Summer-2021.git
```
This will create a directory named **ECE264-Summer-2021** that contains everything you see right here. Do not modify its name or anything inside. Doing so can complicate the process of downloading any updates to this assignment. Specifically, do not start working on the assignment from inside that directory. First, create a copy of the directory with
```
cp -R ECE264-Summer-2021 <copy name>
```
where `<copy name>` is any name you want (e.g. `Work`, `PAs`, etc.), then do your work inside that copy:
```
cd <copy name>
cd src
vim sort.c
```
We will refer to the `<copy name>` directory as `$WORK` from now on.

### Downloading changes to the assignment

Sometimes, we will make modifications to an assignment after you have already downloaded it and started working on it. To avoid surprises, you will need to keep up-to-date with any modification by pulling changes regularily. If you are in this situation, you will want to first have a look at what the modifications are. Navigate to the **ECE264-Summer-2021** directory and run:
```
git log --name-status -<number of commits to display>
```
where `<number of commits to display>` is the number of commits to the GitHub repository you want to display information for starting with the most recent commit. Commits are committed changes to the repository that we have made. The command
```
git log --name-status -5
```
will display the latest 5 commits to the repository, listing out any files deleted, added or modified for each commit. Each commit is dated, so you need only look at commits that occurred after the last time cloned the repository or pulled changes from it. To look at the actual changes to the code, run:
```
git log -p -<number of commits to display>
```
This will show exactly what changes have been made to the assignment. To pull the changes (that is, make your local repository up-to-date), run:
```
git pull
```
Given that changes we may make to an assignment will be minor, you will find it easy to incorporate the changes to your existing work.

## Goals

The goals of this assignment are:

* To help you become comfortable with your programming environment,
* To motivate you to review the fundamentals of programming,
* To gently introduce you to project management and unit testing.

## Structure

The provided code is organized as follows:

* **src**: This directory contains all the source code for this assignment (excluding unit testing code). Specifically, the code you are required to write for this assignment will go into **sort.c** (where you will find two functions to be defined completely). The file **sort.h** contains the declarations of the functions you are defining in **sort.c** (ignore its contents for now). The file **main.c** defines a `main()` function. Right now, it's empty. As you write your code in **sort.c**, you'll want to test it out by writing some test code in `main()`, compile **sort.c** and **main.c** together, and run the executable (more details in the **How do I start?** section).
* **tests**: This directory contains all the unit testing source code for this assignment. Ignore the contents of these files for now. Just for this assignment, we have provided a complete unit testing suite that you will be able to use easily to make sure your code is correct (more details in the **Testing** section).
* **Makefile**: The Makefile defines how we want make to manage our files (ignore its contents for now).

**Note:** For now, do not modify this structure. The provided Makefile relies on it to function. Once you learn how to write your own Makefile, you will have the option of re-organizing your however you wish.

## Background

Part of this assignment requires you to implement selection sort to sort the elements of an array into a specified order. Visit [the Wiki page on selection sort](https://en.wikipedia.org/wiki/Selection_sort) and refresh your knowledge on how this simple algorithm operates. Note that the C code provided on the Wiki page assumes that the array to be sorted stores integer values. Your task will be to adapt this code to make it work for the arrays you are required to sort in this assignment.

## Requirements

For this assignment, you are required to implement two function: `check_lexicographical_order()` and `sort_lexicographically()`. The requirements for each are defined in the subsections below. Notice the presence of the following preprocessor blocks around the functions:
```
#ifndef TEST_CHECK
  ...
#endif
```
DO NOT REMOVE THESE!

### Check Lexicographical Order

#### Declaration

`bool check_lexicographical_order(char const * phrase, char const * alphabet)`

#### Description

This function verifies that the provided phrase is in lexicographical order, as determined by the provided alphabet.

#### Return Value

This function returns true if the phrase is in lexicographical order. It returns false otherwise.

#### Input

* `phrase`: A C string (with a null terminator at the end). You may assume that each character in the string is one of the 26 letters of the English alphabet, either capitalized or not.
* `alphabet`: A C string. You may assume that the string will be exactly 26 characters long (excluding the null terminator) and contain exactly one instance of each of the 26 letters of the English alphabet, in lower case.

Essentially, you may assume that the inputs to the function are valid and you do not need to check for validity of the input inside the function.

#### Special Rules

Capitalized letters take precedence over their corresponding lower case letters. Thus, `"Aa"` is sorted (regardless of the alphabet), but `"aA"` is not. Assume that an empty input phrase is sorted by default.

#### Examples

* `check_lexicographical_order("aBc", "abcdefghijklmnopqrstuvwxyz")` should return true,
* `check_lexicographical_order("HelloWorld", "abcdefghijklmnopqrstuvwxyz")` should return false,
* `check_lexicographical_order("qweRtY", "qwertyuiopasdfghjklzxcvbnm")` should return true,
* `check_lexicographical_order("ytrewq", "qwertyuiopasdfghjklzxcvbnm")` should return false.

You'll find many more examples in the provided unit test source file for this function.

### Sort Lexicographically

#### Declaration

`void sort_lexicographically(char * phrase, char const * alphabet)`

#### Description

This function sorts the provided phrase in lexicographical order, as determined by the provided alphabet, using selection sort.

#### Return Value

This function has no return value.

#### Input

* `phrase`: A C string (with a null terminator at the end). You may assume that each character in the string is one of the 26 letters of the English alphabet, either capitalized or not.
* `alphabet`: A C string. You may assume that the string will be exactly 26 characters long (excluding the null terminator) and contain exactly one instance of each of the 26 letters of the English alphabet, in lower case.

Again, no input checking is required.

#### Special Rules

Capitalized letters take precedence over their corresponding lower case letters. Thus, `"Aa"` is sorted (regardless of the alphabet), but `"aA"` is not.

#### Examples

* `sort_lexicographically("HelloWorld", "abcdefghijklmnopqrstuvwxyz")` should sort the phrase into `"deHllloorW"`,
* `sort_lexicographically("HelloWorld", "qwertyuiopasdfghjklzxcvbnm")` should sort the phrase into `"WeroodHlll"`.

### Helper Functions

You will want to (but are not required to) create helper functions as you write your code (e.g. a helper function to swap characters inside the phrase). These helper functions should be defined **outside** of the `#ifndef` preprocessor guards as much as possible. If you keep the helper function definition inside of these guards, we could run into potential problems during grading if your helper function is used by several required functions.

## Grading

To grade this assignment, we will use the exact same unit test suite as is provided to you (only for this assignment). When you look into the unit test source files (**test_check_lexicographical_order.c** and **test_sort_lexicographically.c**), you'll notice that the unit test for each function is divided into test functions which are named according to what they are testing. Each one is a test case your code either passes or fails. All of them will be weighted the same for this assignment. There is ample opportunity for partial credit.

## How do I start?

Once you have copied over the **PA01** directory and are ready to work on it, navigate to the **src** directory:
```
cd src
```
and open the **sort.c** and **main.c** files. The following command will open both of them in Vim in split screen:
```
vim -O sort.c main.c
```
Write your code. You should start with the check function, since, once you know it works, you can use it to verify that the sort function works. As you write code in **sort.c**, write code in **main.c** that calls your functions and tests your code. To compile your code, use:
```
gcc -std=c11 -g -Wall -Wextra -Wvla -Werror main.c sort.c
```
Remember that this produces and executable with the name **a.out**. To give it another name, say **pa01**, use:
```
gcc -std=c11 -g -Wall -Wextra -Wvla -Werror main.c sort.c -o pa01
```
Assuming the above compiles your code without errors, you may run your code:
```
./a.out
```
Repeat the process until you are satisfied with your work.

## Compiling and Linking

You are required to use the GCC flags `-Wall -Wextra -Wvla -Werror`. We will use these flags to compile your code for grading purposes. If your code does not compile, we cannot grade it.

## Testing Your Code

As described in the **How do I start?** section, you'll initially be writing test code inside of **src/main.c**. Eventually, you'll want to start running the provided unit tests. To do so, navigate to the directory where the provided Makefile is, and run:
```
make run-test-check
```
to run the unit test for the check function. Once all test cases pass for that function, run:
```
make run-test-sort
```
to test the sort function. Note that the unit test suite for the sorting function relies on a working implementation of your checking function. If your checking function does not work properly, whatever `make run-test-sort` outputs is probably way off. When we grade your, we will use our own version of the checking function so as to isolate each function and provide partial credit (that's why we have the preprocessor guards `#ifndef GRADE_SORT` and `#ifndef GRADE_CHECK`). Once all provided test cases pass, you can be confident that you will earn 100%. Make sure your code compiles with the required GCC flags!

## Submission

Navigate to the **src** directory where you **sort.c** file is, and compress it with:
```
zip sort.zip sort.c
```
Then, upload the **sort.zip** file to Brightspace in the appropriate submission box. Only the last submission is kept by Brightspace, and that's the one we will grade.
