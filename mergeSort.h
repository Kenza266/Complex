#include "functions.h"

uint64_t mergeSort(int n){

    srand (time(NULL));

    int T[n], i, x=random(RANGE);

    for (i=0; i<n; i++)
        T[i] = random(RANGE);

    int r = 0;
    uint64_t time = ns();

    // THE SORT GOES HERE

    time = ns()-time;
    printf("The table is now sorted\n");
    return time;
}
