#include "manageWords.h"

void getAllWordsOfFile(char* fileName, char** arrayWords, unsigned int* size) {
    
    FILE *file;
    char str[MAX_CHAR];
    char newFileName[MAX_CHAR_FILE_NAME];
    char *word;
    
    strcpy(newFileName, fileName);
    strcat(newFileName, ".txt");
    
    file = fopen(newFileName, "r");
    
    if (fileNotFound(file)) {
        printf("Error opening file!\n");
    }
    else {
        
        while (itIsNotTheEndOfFIle(file)) {

            if (fscanf(file, "%s", str) == 1) {
                
                word = (char*) malloc(MAX_CHAR * sizeof(char));

                strcpy(word, str);

                arrayWords[*size] = word;

//                strcpy(arrayWords[*size].content, str);
                (*size)++;
            }
            
        }
        
        fclose(file);
    }

}

Word* countUniqueWords(char *fileName, long size, unsigned int *sizeWords) {

    int i, j;
    FILE *file;
    Word* words = (Word*) malloc(size * sizeof(Word));
    char word[MAX_CHAR];
    char str[MAX_CHAR];
    int isEqual = TRUE;
    int countAppearances;
    char newFileName[MAX_CHAR_FILE_NAME];
    
    strcpy(newFileName, fileName);
    strcat(newFileName, "_sorted");
    strcat(newFileName, ".txt");
    
    file = fopen(newFileName, "r");
    
    if (fileNotFound(file)) {
        printf("Error reading file!\n");
    }
    else {
        
        fscanf(file, "%s", str);
        
        while (itIsNotTheEndOfFIle(file)) {
            
            strcpy(word, str);
            isEqual = TRUE;
            countAppearances = 1;

            while (itIsNotTheEndOfFIle(file) && isEqual == TRUE) {
//                printf("1\n");
                if (fscanf(file, "%s", str) == 1) {
//                    printf("2\n");
                    
                    if(strcmp(word, str) == 0) {
//                        printf("3\n");
                        countAppearances++;
                    }
                    else {
//                        printf("4\n");
//                        printf("%s\n", word);
                        strcpy(words[*sizeWords].content, word);
                        words[*sizeWords].appearances = countAppearances;
                        (*sizeWords)++;
                        isEqual = FALSE;
                    }
                    
                }
            }
            
                
        }
        
//        printf("%u\n", *sizeWords);
        fclose(file);
    }

    return words;

} 

void saveWordsToFile(char *fileName, char **arrayWords, unsigned int size) {
    
    FILE *file;
    char str[MAX_CHAR];
    unsigned int i;
    char newFileName[MAX_CHAR_FILE_NAME];
    
    strcpy(newFileName, fileName);
    strcat(newFileName, "_sorted");
    strcat(newFileName, ".txt");
    
    file = fopen(newFileName, "w");
    
    if (fileNotFound(file)) {
        printf("Error creating file!\n");
    }
    else {
        
        for (i = 0; i < size; i++) {
//            fprintf(file, "%s\n", arrayWords[i].content);
            fprintf(file, "%s\n", arrayWords[i]);
        }
        
        fclose(file);
    }
    
}

void saveUniqueWordsToFile(char *fileName, Word *arrayWords, unsigned int size) {
    
    FILE *file;
    char str[MAX_CHAR];
    unsigned int i;
    char newFileName[MAX_CHAR_FILE_NAME];
    
    strcpy(newFileName, fileName);
    strcat(newFileName, "_counted");
    strcat(newFileName, ".txt");
    
    file = fopen(newFileName, "w");
    
    if (fileNotFound(file)) {
        printf("Error creating file!\n");
    }
    else {
        
        for (i = 0; i < size; i++) {
            fprintf(file, "%s %u\n", arrayWords[i].content, arrayWords[i].appearances);
        }
        
        fclose(file);
    }
    
}

void saveRankedWordsToFile(char *fileName, Word *arrayWords, unsigned int size) {
    
    FILE *file;
    char str[MAX_CHAR];
    unsigned int i, j, k;
    char newFileName[MAX_CHAR_FILE_NAME];
    unsigned int currentNumber;
    unsigned int begin, end;
    
    strcpy(newFileName, fileName);
    strcat(newFileName, "_ranked");
    strcat(newFileName, ".txt");
    
    file = fopen(newFileName, "w");
    
    if (fileNotFound(file)) {
        printf("Error creating file!\n");
    }
    else {
        i = size;
        j = 0;
        while (i > 0 && j < 100) {
            
            currentNumber = arrayWords[i-1].appearances;
//            begin = i-1;
            end = i-1;
            
            while (arrayWords[i-1].appearances == currentNumber && i > 0 && j < 100) {
                j++;
                i--;
            }
            
            begin = i;
            
            for (k=begin; k<=end; k++) {
                fprintf(file, "%s %u\n", arrayWords[k].content, arrayWords[k].appearances);
            }
            
//            j++;
//            i--;
        }
        
        fclose(file);
    }
    
}

int fileNotFound(FILE *file) {
    
    int isFileNotFound = FALSE;
    
    if (file == NULL) {
        isFileNotFound = TRUE;
    }
    
    return isFileNotFound;
}

int itIsNotTheEndOfFIle(FILE *file) {
    
    int isNotTheEndOfFile = TRUE;
    
    if (feof(file)) {
        isNotTheEndOfFile = FALSE;
    }
    
    return isNotTheEndOfFile;
    
}
