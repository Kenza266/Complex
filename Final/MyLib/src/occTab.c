#include "../headers/functions.h"
#include "../headers/occTab.h"

uint64_t occTab(int n){

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
    printf("\nThe value %d appeared %d times in the table\n", x, r);
    
    return time;

}
