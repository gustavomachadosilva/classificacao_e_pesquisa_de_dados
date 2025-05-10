#ifndef manageWords_h
#define manageWords_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 30
#define TRUE 1
#define FALSE 0
#define MAX_CHAR_FILE_NAME 50

typedef struct {
    char content[MAX_CHAR];
    unsigned int appearances;
} Word;

void getAllWordsOfFile(char* fileName, char** arrayWords, unsigned int* size);
Word* countUniqueWords(char *fileName, long size, unsigned int *sizeWords);
void saveWordsToFile(char *fileName, char **arrayWords, unsigned int size);
void saveUniqueWordsToFile(char *fileName, Word *arrayWords, unsigned int size);
int fileNotFound(FILE *file);
int itIsNotTheEndOfFIle(FILE *file);
void saveRankedWordsToFile(char *fileName, Word *arrayWords, unsigned int size);

#endif /* manageWords_h */
