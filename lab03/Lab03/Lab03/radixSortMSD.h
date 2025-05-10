#ifndef radixSortMSD_h
#define radixSortMSD_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "manageWords.h"

#define ASCII 256

void radixSortMSD(char **array, long left, long right, int digit);
void countFrequency(char** array, int* count, long left, long right, int digit);
void sumValues(int* count, int maxValue);
char** allocateArrayAux(long left, long right);
void fillArrayAux(char** arrayAux, char** mainArray, int* count, long left, long right, int digit);
void copyArrayAuxToMain(char** arrayAux, char** arrayMain, long left, long right);
void recursion(char **array, int *count, long left, long right, int digit);
void printStrings(char **arr, int n);


#endif /* radixSortMSD_h */
