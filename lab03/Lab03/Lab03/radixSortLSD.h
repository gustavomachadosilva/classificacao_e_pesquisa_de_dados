#ifndef radixSortLSD_h
#define radixSortLSD_h

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "manageWords.h"

#define COUNT_SIZE 9

void radixSortLSD(Word* array, unsigned int size);
int identifyDigit(int number, int decimalPlace);
int countDigits(int maxValue);
unsigned int findMaxValue(Word* arrayWords, unsigned int size);
int* allocateCount(int maxValue);
Word* allocateArrayAux2(int size);
void countValues(Word* arrayWords, int* count, int arraySize, int decimalPlace);
void sumValues2(int* count, int maxValue);
void fillArrayAux2(Word* arrayAux, Word* mainArray, int* count, int size, int decimalPlace);
void copyArrayAuxToMain2(Word* arrayAux, Word* arrayMain, int size);
void clearArray(int* array, int size);
void printArray(int* array, int size);

#endif /* radixSortLSD_h */
