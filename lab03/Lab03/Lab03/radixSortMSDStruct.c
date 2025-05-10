#include "radixSortMSDStruct.h"

void radixSortMSDStruct(Word *arrayWords, unsigned int left, unsigned int right, unsigned int digit) {

    if (right > left) {

        unsigned int count[ASCII + 2] = {0};
        Word* aux;
//        printf("passou declaracao\n");
        
//        printf("left: %u - right: %u - digit = %d\n", left, right, digit);
        countFrequencyStruct(arrayWords, count, left, right, digit);
//        printf("passou contagem\n");
        
        sumValuesStruct(count, ASCII);
//        printf("passou soma\n");

        aux = allocateArrayAuxStruct(left, right);
//        printf("passou alocacao aux\n");
        
        fillArrayAuxStruct(aux, arrayWords, count, left, right, digit);
//        printf("passou preenche aux\n");
        
        copyArrayAuxToMainStruct(aux, arrayWords, left, right);
//        printf("passou copia\n");
        
        free(aux);
//        printf("passou free\n");
        
//        printStrings(arrayWords, right+1);
        
        
        recursionStruct(arrayWords, count, left, right, digit);

    } 

}


void countFrequencyStruct(Word *arrayWords, unsigned int* count, unsigned int left, unsigned int right, unsigned int digit) {

    unsigned int i;
    unsigned int index;
    
//    printf("%d\n", digit);
//    printf("index: %d\n", arrayWords[left].content[digit]);
    for (i=left; i<=right; i++) {
        index = arrayWords[i].content[digit];
//        printf("%d\n", index);
        count[index + 2]++;
    }

}

void sumValuesStruct(unsigned int* count, unsigned int maxValue) {

    for (unsigned int i = 0; i < ASCII + 1; i++) {
        count[i + 1] += count[i];
    }

}

Word* allocateArrayAuxStruct(unsigned int left, unsigned int right) {

    Word* array = (Word*) malloc((right - left + 1) * sizeof(Word));

    return array;

}

void fillArrayAuxStruct(Word *arrayAux, Word *mainArray, unsigned int* count, unsigned int left, unsigned int right, unsigned int digit) {
    unsigned int i;
    unsigned int index, position;

    for (i=left; i<=right; i++) {
        index = mainArray[i].content[digit];
        count[index + 1] += 1;
        position = count[index + 1] - 1;
//        arrayAux[position] = mainArray[i];
        arrayAux[position].appearances = mainArray[i].appearances;
        strcpy(arrayAux[position].content, mainArray[i].content);
    }
}

void copyArrayAuxToMainStruct(Word *arrayAux, Word *arrayMain, unsigned int left, unsigned int right) {

    unsigned int i;

    for (i=left; i<=right; i++) {
//        arrayMain[i] = arrayAux[i - left];
        arrayMain[i].appearances = arrayAux[i - left].appearances;
        strcpy(arrayMain[i].content, arrayAux[i - left].content);
//        printf("%s\n", arrayMain[i].content);
        // strcpy(arrayMain[i], arrayAux[i - left]);
    }

}

void recursionStruct(Word *array, unsigned int *count, unsigned int left, unsigned int right, unsigned int digit) {

    unsigned int i;
    
//    printf("left: %u - right: %u - digit = %d\n", left, right, digit);
//    printf("passou1\n");
//    printf("%p - %s\n", array, array[0].content);
//    printf("passou2\n");

    for (i=0; i<ASCII; i++) {
//        printf("%u - %u\n", count[i+1], count[i]);
//        printf("%d", i);
         if (count[i+1] > count[i]) {
            radixSortMSDStruct(array, left + count[i], left + count[i+1] - 1, digit + 1);
         }
    }
}

void printStringsStruct(Word *arrayWords, int n) {

    int i;

    for(i=0; i<n; i++) {
        printf("%s\n", arrayWords[i].content);
    }

    printf("\n");

}
