#include "radixSortMSD.h"

void radixSortMSD(char **array, long left, long right, int digit) {

    if (right > left) {

        int count[ASCII + 2] = {0};
        char** aux;

        countFrequency(array, count, left, right, digit);
        sumValues(count, ASCII);
        // printf("passou soma\n");

        aux = allocateArrayAux(left, right);
        // printf("passou aloca aux\n");

        fillArrayAux(aux, array, count, left, right, digit);
        // printf("passou preenche aux\n");

        // printStrings(aux, 6);

        copyArrayAuxToMain(aux, array, left, right);
        // printf("passou copia\n");

        free(aux);
        // printf("passou libera\n");

        // printStrings(array, 6);

        recursion(array, count, left, right, digit);
        // printf("passou recursao\n");

    } 

}


void countFrequency(char** array, int* count, long left, long right, int digit) {

    int i;
    int index;

    for (i=left; i<=right; i++) {
        index = array[i][digit];
        count[index + 2]++;
    }

}

void sumValues(int* count, int maxValue) {

    for (int i = 0; i < ASCII + 1; i++) {
        count[i + 1] += count[i];
    }

}

char** allocateArrayAux(long left, long right) {

    char** array = malloc((right - left + 1) * sizeof(char*));

    return array;

}

void fillArrayAux(char** arrayAux, char** mainArray, int* count, long left, long right, int digit) {
    // printf("entrou preenche\n");
    int i;
    int index, position;

    for (i=left; i<=right; i++) {
        // printf("%d - %s\n", i, mainArray[i]);
        index = mainArray[i][digit];
        // printf("index - %d\n", index);
        // printf("passou 1\n");
        count[index + 1] += 1;
        // printf("index count - %d\n", count[index + 1]);
        // printf("passou 2\n");
        position = count[index + 1] - 1;
        // printf("passou 3\n");
        // printf("%d - %s\n", i, mainArray[i]);
        arrayAux[position] = mainArray[i];
        // printf("%d - position %d - %s\n", i, position, arrayAux[position]);
        // strcpy(arrayAux[position], mainArray[i]);
        // printf("passou 4\n");
    }
}

void copyArrayAuxToMain(char** arrayAux, char** arrayMain, long left, long right) {

    int i;

    for (i=left; i<=right; i++) {
        arrayMain[i] = arrayAux[i - left];
        // strcpy(arrayMain[i], arrayAux[i - left]);
    }

}

void recursion(char **array, int *count, long left, long right, int digit) {

    int i;

    for (i=0; i<ASCII; i++) {
        // if (count[i+1] > count[i]) {
            radixSortMSD(array, left + count[i], left + count[i+1] - 1, digit + 1);
        // }
    }
}

void printStrings(char **arr, int n) {

    int i;

    for(i=0; i<n; i++) {
        printf("%s\n", arr[i]);
    }

    printf("\n");

}