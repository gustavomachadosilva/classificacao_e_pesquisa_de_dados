#include <stdio.h>
#include "radixSortLSD.h"

#define MAX 15



int main(void) {

    int array[MAX] = {3221, 1, 10, 9680, 577, 9420, 7, 5622, 4793, 2030, 3138, 82, 2599, 743, 4127};

    printArray(array, MAX);

    radixSortLSD(array, MAX);

    printArray(array, MAX);

    return 0;
}

