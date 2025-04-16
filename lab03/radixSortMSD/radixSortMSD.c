#include "radixSortMSD.h"

void radixSortMSD(char **array, int left, int right, int digit) {

    if (right > left) {

        int count[ASCII + 2] = {0};
        char** aux;

        sumValues(count, ASCII);
        printf("passou soma\n");

        aux = allocateArrayAux(left, right);
        printf("passou aloca aux\n");

        fillArrayAux(aux, array, count, left, right, digit);
        printf("passou preenche aux\n");

        copyArrayAuxToMain(aux, array, left, right);
        printf("passou copia\n");

        free(aux);
        printf("passou libera\n");

        recursion(array, count, left, right, digit);
        printf("passou recursao\n");

    } 
    
    return;

}


void countFrequency(char** array, int* count, int left, int right, int digit) {

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

char** allocateArrayAux(int left, int right) {

    char** array = malloc((right - left + 1) * sizeof(char*));

    return array;

}

void fillArrayAux(char** arrayAux, char** mainArray, int* count, int left, int right, int digit) {
    printf("entrou preenche\n");
    int i;
    int index, position;

    for (i=left; i<=right; i++) {
        index = mainArray[i][digit];
        printf("passou 1\n");
        count[index + 1]++;
        printf("passou 2\n");
        position = count[index + 1];
        printf("passou 3\n");
        arrayAux[position] = mainArray[i];
        printf("passou 4\n");
    }
}

void copyArrayAuxToMain(char** arrayAux, char** arrayMain, int left, int right) {

    int i;

    for (i=left; i<=right; i++) {
        arrayMain[i] = arrayAux[i - left];
    }

}

void recursion(char **array, int *count, int left, int right, int digit) {

    int i;

    for (i=0; i<ASCII; i++) {
        // if (count[i+1] > count[i]) {
            radixSortMSD(array, left + count[i], left + count[i+1] - 1, digit + 1);
        // }
    }
}