#include "countingSort.h"

void countingSort(int *array, int size) {

    int maxValue;
    int* count;
    int* arrayAux;

    maxValue = findMaxValue(array, size);
    count = allocateCount(maxValue);

    arrayAux = allocateArrayAux(size);

    countValues(array, count, size);
    sumValues(count, maxValue);

    fillArrayAux(arrayAux, array, count, size);

    copyArrayAuxToMain(arrayAux, array, size);

    free(count);
    free(arrayAux);

}

void countingSortWithMaxValue(int *array, int size, int maxValue) {

    int* count;
    int* arrayAux;

    count = allocateCount(maxValue);

    arrayAux = allocateArrayAux(size);

    countValues(array, count, size);
    sumValues(count, maxValue);

    fillArrayAux(arrayAux, array, count, size);

    copyArrayAuxToMain(arrayAux, array, size);

    free(count);
    free(arrayAux);

}

int findMaxValue(int* array, int size) {

    int i;
    int maxValue = 0;

    for (i=0; i<size; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    return maxValue;
}

int* allocateCount(int maxValue) {

    int* array = (int*) calloc((maxValue+1), sizeof(int));

    return array;

}

int* allocateArrayAux(int size) {

    int* array = (int*) malloc(size * sizeof(int));

    return array;
}

void countValues(int* array, int* count, int arraySize) {

    int i;
    int countIndex;

    for (i=0; i<arraySize; i++) {
        countIndex = array[i];
        count[countIndex]++;
    }

}

void sumValues(int* count, int maxValue) {

    int i;

    for (i=1; i<=maxValue; i++) {
        count[i] += count[i-1];
    }

}

void fillArrayAux(int* arrayAux, int* mainArray, int* count, int size) {

    int i;
    int number, position;

    for (i=(size - 1); i>=0; i--) {
        number = mainArray[i];
        count[number] -= 1;
        position = count[number];
        arrayAux[position] = number;
    }
}

void copyArrayAuxToMain(int* arrayAux, int* arrayMain, int size) {

    int i;

    for (i=0; i<size; i++) {
        arrayMain[i] = arrayAux[i];
    }

}