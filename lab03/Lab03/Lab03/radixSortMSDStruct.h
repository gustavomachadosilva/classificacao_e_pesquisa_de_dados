#ifndef radixSortMSDStruct_h
#define radixSortMSDStruct_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "manageWords.h"

#define ASCII 256

void radixSortMSDStruct(Word *arrayWords, unsigned int left, unsigned int right, unsigned int digit);
void countFrequencyStruct(Word *arrayWords, unsigned int* count, unsigned int left, unsigned int right, unsigned int digit);
void sumValuesStruct(unsigned int* count, unsigned int maxValue);
Word* allocateArrayAuxStruct(unsigned int left, unsigned int right);
void fillArrayAuxStruct(Word *arrayAux, Word *mainArray, unsigned int* count, unsigned int left, unsigned int right, unsigned int digit);
void copyArrayAuxToMainStruct(Word *arrayAux, Word *arrayMain, unsigned int left, unsigned int right);
void recursionStruct(Word *array, unsigned int *count, unsigned int left, unsigned int right, unsigned int digit);
void printStringsStruct(Word *arrayWords, int n);

#endif /* radixSortMSDStruct_h */
