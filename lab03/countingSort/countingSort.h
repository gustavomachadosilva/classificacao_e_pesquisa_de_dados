#ifndef countingSort_h
#define countingSort_h

#include <stdlib.h>

void countingSort(int *array, int size);
void countingSortWithMaxValue(int *array, int size, int maxValue);
int findMaxValue(int* array, int size);
int* allocateCount(int maxValue);
int* allocateArrayAux(int size);
void countValues(int* array, int* count, int arraySize);
void sumValues(int* count, int maxValue);
void fillArrayAux(int* arrayAux, int* mainArray, int* count, int size);
void copyArrayAuxToMain(int* arrayAux, int* arrayMain, int size);

#endif /* countingSort_h */

