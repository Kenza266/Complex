#include "functions.h"
 
int main()
{
    disks = 4;
    create();
    printf("The matrix:\n");
    print();
    time = ns();
    hanoifun(disks, 0, 2, 1); // Source, Destination, Auxilary
    time = ns()-time;
    time /=1000000;
    printf("With %d disks, the execution time: %llums \n", disks, time);
    return 0;
}
