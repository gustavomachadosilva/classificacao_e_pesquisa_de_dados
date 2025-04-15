#include <stdio.h>
#include "countingSort.h"

#define MAX 12

void printArray(int* array, int size);

int main(void) {

    int array[MAX] = {9, 3, 3, 2, 1, 4, 3, 9, 4, 1, 3, 3};

    printArray(array, MAX);

    countingSortWithMaxValue(array, MAX, 9);

    printArray(array, MAX);

    return 0;
}

void printArray(int* array, int size) {

    int i;

    for (i=0; i<size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

}