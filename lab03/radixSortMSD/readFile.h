#ifndef readFile_h
#define readFile_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 20

void getAllWordsOfFile(char* fileName, char** array, long* size);
char** identifyUniqueWords(char **array, long size, long *sizeWords);
int* countValues(char** array, char** uniqueWords, long size, long sizeWords);

#endif /* readFile_h */