#include "functions.h"

uint64_t matSum(int n){

    srand (time(NULL));
    int A[n][n], B[n][n], C[n][n], i, j;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            A[i][j] = random(RANGE);
            A[i][j] = random(RANGE);
        }

    uint64_t time = ns();
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            C[i][j] = A[i][j] + B[i][j];
    time = ns()-time;
    printf("The sum has been calculated\n");
    return time;
}
