//
//  quickSort.c
//  Lab02QuickSort
//
//  Created by Gustavo Machado Silva on 01/04/25.
//

#include "quickSort.h"

void quickSort(int values[], int begin, int final, int partitionerType, int partitionType, int *recursions, int *numSwap) {
    
    int partitioner;
    
    *recursions += 1;
    
    if (final > begin) {
        
        setPartitioner(values, begin, final, partitionerType, numSwap);
        
        partitioner = partition(values, begin, final, partitionType, numSwap);
        
        quickSort(values, begin, partitioner-1, partitionerType, partitionType, recursions, numSwap);
        quickSort(values, partitioner+1, final, partitionerType, partitionType, recursions, numSwap);
    }
    
}

void setPartitioner(int values[], int begin, int final, int partitionerType, int *numSwap) {
    
    switch (partitionerType) {
        case TRADITIONAL:
            break;
        case RANDOM:
            randomPartitioner(values, begin, final, numSwap);
            break;
        case MEDIAN_OF_THREE:
            medianOfThreePartioner(values, begin, final, numSwap);
            break;
        default:
            break;
    }
    
}

int partition(int values[], int begin, int final, int partitionType, int *numSwap) {
    
    int partitioner;
    
    switch (partitionType) {
        case LOMUTO:
            partitioner = partition_lomuto(values, begin, final, numSwap);
            break;
        case HOARE:
            partitioner = partition_hoare(values, begin, final, numSwap);
            break;
            
        default:
            partitioner = partition_lomuto(values, begin, final, numSwap);
            break;
    }
    
    return partitioner;
    
}

int partition_lomuto(int values[], int left, int right, int *numSwap) {
    
    int key = values[left];
    int indexOfSmallerElement = left + 1;
    int i;
    
    for (i = left + 1; i <= right; i++) {
        if (values[i] < key) {
            swapTwoArrayValues(values, i, indexOfSmallerElement, numSwap);
            indexOfSmallerElement++;
        }
    }
    
    swapTwoArrayValues(values, left, indexOfSmallerElement-1, numSwap);
    return indexOfSmallerElement-1;
    
}

int partition_hoare(int values[], int left, int right, int *numSwap) {
    
    int i, j;
    int key;
    
    key = values[left];
    i = left;
    j = right + 1;
    
    while (1) {
        while (values[++i] <= key) if (i == right) break;
        while (key < values[--j]) if (j == left) break;
        if (i >= j) break;
        swapTwoArrayValues(values, i, j, numSwap);
    }
    
    swapTwoArrayValues(values, left, j, numSwap);
    return j;
    
    
}

void swapTwoArrayValues(int values[], int indexFirst, int indexSecond, int *numSwap) {
    
    int aux;
    
    aux = values[indexFirst];
    values[indexFirst] = values[indexSecond];
    values[indexSecond] = aux;
    
    (*numSwap)++;
    
}

void randomPartitioner(int values[], int begin, int final, int *numSwap) {
    
    int numValues, randomNumber;
    
    numValues = final - begin;
    randomNumber = begin + (rand() % (numValues + 1));
    
    swapTwoArrayValues(values, begin, randomNumber, numSwap);
    
}

void medianOfThreePartioner(int values[], int begin, int final, int *numSwap) {
    
    int medianValue;
    
    medianValue = ((final - begin) / 2) + begin;
    
    if ((values[medianValue] > values[begin] && values[medianValue] < values[final]) || (values[medianValue] > values[final] && values[medianValue] < values[begin])) {
        swapTwoArrayValues(values, begin, medianValue, numSwap);
    }
    else if ((values[final] > values[medianValue] && values[final] < values[begin]) || (values[final] > values[begin] && values[final] < values[medianValue])) {
        swapTwoArrayValues(values, begin, final, numSwap);
    }
    
}
