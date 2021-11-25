#include "MyLib/headers/treePrint.h"
#include "MyLib/headers/occTab.h"
#include "MyLib/headers/mergeSort.h"
#include "MyLib/headers/matSum.h"

#include "MyLib/headers/functions.h" 

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

        if (!option) 
            break;

        printf("\nSize ");
        scanf("%d", &n);
        
        count=0;
        run(func_ptr[option-1], n); 

    }   
    
    return 0;

}
