#ifndef radixSortLSD_h
#define radixSortLSD_h

#include <stdlib.h>
#include <stdio.h>

#define ASCII 256

void radixSortMSD(char **array, int left, int right, int digit);
void sumValues(int* count, int maxValue);
char** allocateArrayAux(int left, int right);
void fillArrayAux(char** arrayAux, char** mainArray, int* count, int left, int right, int digit);
void copyArrayAuxToMain(char** arrayAux, char** arrayMain, int left, int right);
void recursion(char **array, int *count, int left, int right, int digit);

#endif /* radixSortLSD_h */