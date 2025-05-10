#include "radixSortLSD.h"

void radixSortLSD(Word* arrayWords, unsigned int size) {
    
    int i;
    unsigned int maxValue;
    int* count;
    Word* arrayAux;
    int digits;

    maxValue = findMaxValue(arrayWords, size);

    if (maxValue > 0) {

        digits = countDigits(maxValue);

        count = allocateCount(COUNT_SIZE);
        arrayAux = allocateArrayAux2(size);

        // printArray(array, size);

        for (i=0; i<digits; i++) {

            // printf("\nstep %d ------\n", i);

            clearArray(count, COUNT_SIZE + 1);
            countValues(arrayWords, count, size, i);
            // printf("Counting values:\n");
            // printArray(count, COUNT_SIZE + 1);
            sumValues2(count, COUNT_SIZE);
            // printf("\nadding values:\n");
            // printArray(count, COUNT_SIZE + 1);

            fillArrayAux2(arrayAux, arrayWords, count, size, i);

            copyArrayAuxToMain2(arrayAux, arrayWords, size);
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

unsigned int findMaxValue(Word* arrayWords, unsigned int size) {

    unsigned int i;
    unsigned int maxValue = 0;

    for (i=0; i<size; i++) {
        if (arrayWords[i].appearances > maxValue) {
            maxValue = arrayWords[i].appearances;
        }
    }

    return maxValue;
}

int* allocateCount(int maxValue) {

    int* array = (int*) malloc((maxValue+1) * sizeof(int));

    return array;

}

Word* allocateArrayAux2(int size) {

    Word* array = (Word*) malloc(size * sizeof(Word));

    return array;
}

void countValues(Word* arrayWords, int* count, int arraySize, int decimalPlace) {

    int i;
    int digit;

    for (i=0; i<arraySize; i++) {
        digit = identifyDigit(arrayWords[i].appearances, decimalPlace);
        count[digit]++;
    }

}

void sumValues2(int* count, int maxValue) {

    int i;

    for (i=1; i<=maxValue; i++) {
        count[i] += count[i-1];
    }

}

void fillArrayAux2(Word* arrayAux, Word* mainArray, int* count, int size, int decimalPlace) {

    int i;
    int number, position, digit;

    for (i=(size - 1); i>=0; i--) {
        number = mainArray[i].appearances;
        digit = identifyDigit(number, decimalPlace);
        count[digit] -= 1;
        position = count[digit];
        strcpy(arrayAux[position].content, mainArray[i].content);
        arrayAux[position].appearances = number;
    }
}

void copyArrayAuxToMain2(Word* arrayAux, Word* arrayMain, int size) {

    int i;

    for (i=0; i<size; i++) {
        strcpy(arrayMain[i].content, arrayAux[i].content);
        arrayMain[i].appearances = arrayAux[i].appearances;
//        arrayMain[i] = arrayAux[i];
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
