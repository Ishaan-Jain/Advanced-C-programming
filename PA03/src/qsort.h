////////////////////////////////////////////////////////////////////////////////
//                                   qsort.h                                  //
////////////////////////////////////////////////////////////////////////////////
#ifndef __QSORT_H__
#define __QSORT_H__

#include <stdio.h>

#define COUNT_FAIL 	-1
#define READ_FAIL	-1
#define WRITE_FAIL	-1

int count_int_from_file(FILE *stream);
int read_int_from_file(FILE *stream, int *buffer, int size);
int write_int_to_file(FILE *stream, int *buffer, int size);
int compare_int(const void *first, const void *second);
void sort_int_with_qsort(int *buffer, int size);

#endif // __QSORT_H__
////////////////////////////////////////////////////////////////////////////////
//                                 END OF FILE                                //
////////////////////////////////////////////////////////////////////////////////
