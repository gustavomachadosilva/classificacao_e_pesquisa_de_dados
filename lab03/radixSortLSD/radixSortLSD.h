#ifndef radixSortLSD_h
#define radixSortLSD_h

#include <math.h>
#include<stdlib.h>
#include <stdio.h>

#define COUNT_SIZE 9

void radixSortLSD(int* array, int size);
int identifyDigit(int number, int decimalPlace);
int countDigits(int maxValue);
int findMaxValue(int* array, int size);
int* allocateCount(int maxValue);
int* allocateArrayAux(int size);
void countValues(int* array, int* count, int arraySize, int decimalPlace);
void sumValues(int* count, int maxValue);
void fillArrayAux(int* arrayAux, int* mainArray, int* count, int size, int decimalPlace);
void copyArrayAuxToMain(int* arrayAux, int* arrayMain, int size);
void clearArray(int* array, int size);
void printArray(int* array, int size);

#endif /* radixSortLSD_h */