#include "functions.h"
 
int main()
{
    printf("Please enter the size of the problem: ");
    scanf("%d", &disks);
    while (disks<=0){
        printf("The size must be positive, try again: ");
        scanf("%d", &disks);
    }
    create();
    printf("The matrix:\n");
    print();
    int source=0, destination=2, aux=1;
    time = ns();
    hanoifun(disks, source, destination, aux); // Source, Destination, Auxilary
    time = ns()-time;
    time *=1e-6; // Convert from ns to ms

    print_report();
    printf("\nExecuting the verification algorithm...\n\n");

    if (verify(source, destination))
        printf("Task finished succesfully");
    else 
        printf("Error");
    return 0;
}
