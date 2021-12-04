#include "../headers/functions.h"
#include "../headers/occTab.h"

int* occTab(int n){

    srand (time(NULL));

    int T[n], i, r=0, x=randnum(MIN, MAX);

    for (i=0; i<n; i++)
        T[i] = randnum(MIN, MAX);

    uint64_t time = ns();
    for (i=0; i<n; i++){
        count++;
        if (T[i]==x)
            r++;
    }
    time = ns()-time;

    printf("\nThe value %d appeared %d time(s) in the table\n", x, r);
    
    int* ret = (int*) malloc(sizeof(int) * 2);
    *ret = time;
    *(ret+1) = count;

    return ret;
}
