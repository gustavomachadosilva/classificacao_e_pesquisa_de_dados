#include "radixSortLSD.h"

void radixSortLSD(int* array, int size) {
    
    int i;
    int maxValue;
    int* count;
    int* arrayAux;
    int digits;

    maxValue = findMaxValue(array, size);

    if (maxValue > 0) {

        digits = countDigits(maxValue);

        count = allocateCount(COUNT_SIZE);
        arrayAux = allocateArrayAux(size);

        // printArray(array, size);

        for (i=0; i<digits; i++) {

            // printf("\nstep %d ------\n", i);

            clearArray(count, COUNT_SIZE + 1);
            countValues(array, count, size, i);
            // printf("Counting values:\n");
            // printArray(count, COUNT_SIZE + 1);
            sumValues(count, COUNT_SIZE);
            // printf("\nadding values:\n");
            // printArray(count, COUNT_SIZE + 1);

            fillArrayAux(arrayAux, array, count, size, i);

            copyArrayAuxToMain(arrayAux, array, size);
            // printf("\n");
            // printArray(array, size);
        }

        free(count);
        free(arrayAux);

    }

}

int identifyDigit(int number, int decimalPlace) {

    int divider = pow(10, decimalPlace);
    int result;

    if (divider >= 10) {
        result = number / divider;
        return result % 10;
    }

    return number % 10;

}

int countDigits(int maxValue) {

    int digits = 0;
    float copyMaxValue = (float) maxValue;

    while (copyMaxValue >= ((float) 1)) {
        copyMaxValue /= (float) 10;
        digits++;
    }
    
    return digits;

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

    int* array = (int*) malloc((maxValue+1) * sizeof(int));

    return array;

}

int* allocateArrayAux(int size) {

    int* array = (int*) malloc(size * sizeof(int));

    return array;
}

void countValues(int* array, int* count, int arraySize, int decimalPlace) {

    int i;
    int digit;

    for (i=0; i<arraySize; i++) {
        digit = identifyDigit(array[i], decimalPlace);
        count[digit]++;
    }

}

void sumValues(int* count, int maxValue) {

    int i;

    for (i=1; i<=maxValue; i++) {
        count[i] += count[i-1];
    }

}

void fillArrayAux(int* arrayAux, int* mainArray, int* count, int size, int decimalPlace) {

    int i;
    int number, position, digit;

    for (i=(size - 1); i>=0; i--) {
        number = mainArray[i];
        digit = identifyDigit(number, decimalPlace);
        count[digit] -= 1;
        position = count[digit];
        arrayAux[position] = number;
    }
}

void copyArrayAuxToMain(int* arrayAux, int* arrayMain, int size) {

    int i;

    for (i=0; i<size; i++) {
        arrayMain[i] = arrayAux[i];
    }

}

void clearArray(int* array, int size) {
    int i;

    for (i=0; i<size; i++) {
        array[i] = 0;
    }
}

void printArray(int* array, int size) {

    int i;

    for (i=0; i<size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

}