## Overview of the Requirements

* Implement the `concat_str` function found in concat_str.c,
* Implement a test suite, either in main.c or in test.c (using acutest.h).

## Requirement Specification

The `concat_str()` function takes as input an input filename `char *filename_in`
and an output filename `char *filename_out`, each of them C strings.

The function must read each line in `filename_in`,
concatenate them together (directly),
and write the concatenated string to `filename_out`.

You can assume the file `filename_in` always exists in the current directory,
and each line in it is at most 80 characters long.
If file `filename_out` already exists, it should be overwritten.


## Examples

Suppose `filename_in` contains:

    Hello
    World

Then, the output file should be expected to look like:

    HelloWorld

If the input file contains

    H ello
        Wor   ld
        
Then the output file should contain

    H ello    Wor   ld

## Testing

You have two options to write your test cases:
* Write your test cases clearly in main.c,
* Write your test cases using acutest in test.c.

Do not do both, choose only one. If you use main.c, we have provided the function `diff()`
which you can use to compare the contents of two files (see comment in code). If you use
acutest.h, you can use the TEST_TWO_FILES_EQUAL macro talked about in lecture and used in
PA03.

## Compiling

If you went with main.c for your testing, the compilation command should be

    gcc -std=c11 -g -Wall -Wextra -Werror main.c concat_str.c
    
If you went with test.c (acutest) for your testing, the compilation command should be

    gcc -std=c11 -g -Wall -Wextra -Werror test.c concat_str.c
    
In either case, the name of the executable will be the default `a.out`. So run using

    ./a.out
    
## Grading

See the rubric posted on Brightspace under CONTENTS.
