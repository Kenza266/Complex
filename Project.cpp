#include "functions.h" 

#include "treePrint.h"
#include "occTab.h"
#include "mergeSort.h"
#include "matSum.h"

uint64_t (*func_ptr[5])(int n) = {occTab, matSum, treePrint, treePrintRec, mergeSort};

int main() {

    int option, n;

    while (1){

        option = 0;

        printf("\n\nMenu :\n");
        printf("\t%d: Quit\n", option++);
        printf("\t%d: Calculating the number of occurrences of a digit in an array\n", option++);
        printf("\t%d: Matrix sum\n", option++);
        printf("\t%d: Inorder display of a binary search tree\n", option++);
        printf("\t%d: Inorder display of a binary search tree (Recursive)\n", option++);
        printf("\t%d: Merge sort of an array\n\n", option++);
        scanf("%d", &option);

        if (not option) 
            break;

        printf("\nSize ");
        scanf("%d", &n);
        
        run(func_ptr[option-1], n); 

    }    
    while (0){

        scanf("%d", &n);
        for (int i=0; i<5; i++)
            run(func_ptr[3], n);
        
    }

    return 0;

}
