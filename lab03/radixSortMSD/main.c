#include <stdio.h>
#include "radixSortMSD.h"
#include "readFile.h"
#include <stdlib.h>

#define TAM 1000000

int main(int argc, char const *argv[]) {
    
    int i;
    long size = 0;
    char **array = (char**) malloc(TAM * sizeof(char*));
    char fileName[MAX_CHAR] = "domcasmurro.txt";
    char **uniqueWords;
    long sizeWords;
    int *count;

    getAllWordsOfFile(fileName, array, &size);

    // printStrings(array, size);

    uniqueWords = identifyUniqueWords(array, size, &sizeWords);

    // printStrings(uniqueWords, sizeWords);

    

    

    // char *arr[] = {
    //     "banana",
    //     "apple",
    //     "orange",
    //     "grape",
    //     "blueberry",
    //     "apricot"};

    // int n = sizeof(arr) / sizeof(arr[0]);

    // printStrings(arr, n);

    radixSortMSD(uniqueWords, 0, sizeWords-1, 0);

    count = countValues(array, uniqueWords, size, sizeWords);

    // printStrings(arr, n);

    for (i=0; i<sizeWords; i++) {
        printf("%s %d\n", uniqueWords[i], count[i]);
    }

    for (i=0; i<size; i++) {
        free(array[i]);
    }

    // for (i=0; i<sizeWords; i++) {
    //     free(uniqueWords[i]);
    // }

    free(count);
    free(array);
    free(uniqueWords);

    return 0;
}


