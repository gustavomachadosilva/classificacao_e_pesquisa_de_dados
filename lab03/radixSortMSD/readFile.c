#include "readFile.h"

void getAllWordsOfFile(char* fileName, char** array, long* size) {
    
    FILE *file;
    char str[MAX_CHAR];
    char *word;
    
    file = fopen(fileName, "r");
    
    if (file == NULL) {
        printf("Error opening file!\n");
    }
    else {
        
        while (!feof(file)) {

            if (fscanf(file, "%s", str) == 1) {

                word = (char*) malloc(MAX_CHAR * sizeof(char));

                strcpy(word, str);

                array[*size] = word;
                (*size)++;
            }
            
        }
        
        fclose(file);
    }

}

char** identifyUniqueWords(char **array, long size, long *sizeWords) {

    int i, j;
    int finded;
    char** words = (char**) malloc(size * sizeof(char*));

    *sizeWords = 0;

    for (i=0; i<size; i++) {
        j=0;
        finded = 0;
        while(j<*sizeWords && finded == 0) {
            if (strcmp(words[j], array[i]) == 0) {
                finded = 1;
            }
            j++;
        }

        if (finded == 0) {
            words[*sizeWords] = array[i];
            (*sizeWords)++;
        }
    }

    return words;

} 

int* countValues(char** array, char** uniqueWords, long size, long sizeWords) {

    int i, j;
    int finded;

    int* count = (int*) calloc(sizeWords, sizeof(int));

    for (i=0; i<size; i++) {
        j=0;
        finded = 0;
        while(j<sizeWords && finded == 0) {
            if (strcmp(uniqueWords[j], array[i]) == 0) {
                finded = 1;
            }
            j++;
        }

        if (finded == 1) {
            count[j-1]++;
        }
    }

    return count;

}

