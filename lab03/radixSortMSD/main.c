#include <stdio.h>
#include "radixSortMSD.h"

void printStrings(char **arr, int n);

int main(int argc, char const *argv[]) {
    
    char *arr[] = {
        "banana",
        "apple",
        "orange",
        "grape",
        "blueberry",
        "apricot"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printStrings(arr, n);

    radixSortMSD(arr, 0, n-1, 0);

    printStrings(arr, n);

    return 0;
}

void printStrings(char **arr, int n) {

    int i;

    for(i=0; i<n; i++) {
        printf("%s\n", arr[i]);
    }

}
