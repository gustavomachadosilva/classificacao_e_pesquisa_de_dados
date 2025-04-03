//
//  quickSort.h
//  Lab02QuickSort
//
//  Created by Gustavo Machado Silva on 01/04/25.
//

#ifndef quickSort_h
#define quickSort_h

#include <stdio.h>
#include <stdlib.h>

#define TRADITIONAL 0
#define RANDOM 1
#define MEDIAN_OF_THREE 2

#define LOMUTO 0
#define HOARE 1

void quickSort(int values[], int begin, int final, int partitionerType, int partitionType, int *recursions, int *numSwap);
void setPartitioner(int values[], int begin, int final, int partitionerType, int *numSwap);
int partition(int values[], int begin, int final, int partitionType, int *numSwap);
int partition_lomuto(int values[], int left, int right, int *numSwap);
int partition_hoare(int values[], int left, int right, int *numSwap);
void swapTwoArrayValues(int values[], int indexFirst, int indexSecond, int *numSwap);
void randomPartitioner(int values[], int begin, int final, int *numSwap);
void medianOfThreePartioner(int values[], int begin, int final, int *numSwap);

#endif /* quickSort_h */
