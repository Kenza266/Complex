#include "../headers/functions.h"
#include "../headers/occTab.h"

int* occTab(int n){

    srand (time(NULL));

    int T[n], i, r=0, x=random(RANGE);

    for (i=0; i<n; i++)
        T[i] = random(RANGE);

    uint64_t time = ns();
    for (i=0; i<n; i++){
        count++;
        if (T[i]==x)
            r++;
    }
    time = ns()-time;
    //printf("\nThe value %d appeared %d times in the table\n", x, r);
    
    int* ret = (int*) malloc(sizeof(int) * 2);
    *ret = time;
    *(ret+1) = count;
    return ret;

}
