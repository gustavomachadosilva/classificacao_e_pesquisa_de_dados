//
//  main.c
//  Lab02QuickSort
//
//  Created by Gustavo Machado Silva on 01/04/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"

#define MAX 1000000
#define MAX_STR 100
#define MAX_RANGES 5

void createRandomArray(int values[], int max);
void printArray(int values[]);
void printResults(int values[], int begin, int final, int partitionerType, int partitionType, char partitionerName[], char partitionName[], FILE *file);

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int i;
    int values[MAX];
    int ranges[MAX_RANGES] = {100, 1000, 10000, 100000, 1000000};
    char fileName[MAX_STR] = "perf-quicksort.csv";
    FILE *file;
    
    file = fopen(fileName, "w");
    
    if (file == NULL) {
        printf("erro\n");
    }
    else {
        
        fprintf(file, "particionamento,tamanho,recursoes,trocas,tempo\n");
        
        for (i = 0; i < MAX_RANGES; i++) {
            
            createRandomArray(values, ranges[i]);
            printResults(values, 0, ranges[i] - 1, RANDOM, LOMUTO, "RANDOM", "LOMUTO", file);
            
        }
        
        for (i = 0; i < MAX_RANGES; i++) {
            
            createRandomArray(values, ranges[i]);
            printResults(values, 0, ranges[i] - 1, RANDOM, HOARE, "RANDOM", "HOARE", file);
            
        }
        
        for (i = 0; i < MAX_RANGES; i++) {
            
            createRandomArray(values, ranges[i]);
            printResults(values, 0, ranges[i] - 1, MEDIAN_OF_THREE, LOMUTO, "MEDIANA3", "LOMUTO", file);
            
        }
        
        for (i = 0; i < MAX_RANGES; i++) {
            
            createRandomArray(values, ranges[i]);
            printResults(values, 0, ranges[i] - 1, MEDIAN_OF_THREE, HOARE, "MEDIANA3", "HOARE", file);
            
        }
        
        
        fclose(file);
    }
    
    
    
//    printArray(values);
    
    
    return 0;
}

void createRandomArray(int values[], int max) {
    
    int i;
    
    for (i = 0; i < max; i++) {
        values[i] = rand() % (max + 1);
    }
    
}

void printArray(int values[]) {
    
    int i;
    
    for (i = 0; i < MAX; i++) {
        printf("%d  ", values[i]);
    }
    
    printf("\n");
}

void printResults(int values[], int begin, int final, int partitionerType, int partitionType, char partitionerName[], char partitionName[], FILE *file) {
    
    int recursions = 0;
    int numSwap = 0;
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    
    quickSort(values, begin, final, partitionType, partitionType, &recursions, &numSwap);
    
    end = clock();
    
    cpu_time_used = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;
    
    fprintf(file, "%s-%s,%d,%d,%d,%f\n", partitionerName, partitionName, final+1, recursions, numSwap, cpu_time_used);
    
}
