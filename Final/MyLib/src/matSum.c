#include "../headers/functions.h"
#include "../headers/matSum.h"

int* matSum(int n){

    srand (time(NULL));
    int A[n][n], B[n][n], C[n][n], i, j;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            A[i][j] = randnum(Min, Max);
            A[i][j] = randnum(Min, Max);
        }

    uint64_t time = ns();
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            count++;
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    time = ns()-time;
    //printf("The sum has been calculated\n");
    int* ret = (int*) malloc(sizeof(int) * 2);
    *ret = time;
    *(ret+1) = count;
    return ret;
}
