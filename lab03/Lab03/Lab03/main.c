#include <stdio.h>
#include "radixSortMSD.h"
#include "manageWords.h"
#include <stdlib.h>
#include "radixSortLSD.h"
#include "radixSortMSDStruct.h"

#define TAM 600000
#define BEGIN 0
#define DIGIT 0

void freeArray(char **array, unsigned int size);

int main(int argc, char const *argv[]) {
    
    unsigned int size = 0;
    char **arrayWords = (char**) malloc(TAM * sizeof(char*));
    char fileName[MAX_CHAR_FILE_NAME] = "war_and_peace";
    unsigned int sizeWords = 0;
    Word *uniqueWords;
    
    getAllWordsOfFile(fileName, arrayWords, &size);
    radixSortMSD(arrayWords,  BEGIN, size-1, DIGIT);
    saveWordsToFile(fileName, arrayWords, size);
    
    freeArray(arrayWords, size);
    
    
    uniqueWords = countUniqueWords(fileName, size, &sizeWords);
    radixSortMSDStruct(uniqueWords,  BEGIN, sizeWords-1, DIGIT);
    saveUniqueWordsToFile(fileName, uniqueWords, sizeWords);
    
    radixSortLSD(uniqueWords, sizeWords);
    saveRankedWordsToFile(fileName, uniqueWords, sizeWords);
    

    free(uniqueWords);

    return 0;
}

void freeArray(char **array, unsigned int size) {
    
    unsigned int i;
    
    for (i=0; i<size; i++) {
        free(array[i]);
    }
    
    free(array);
    
}


