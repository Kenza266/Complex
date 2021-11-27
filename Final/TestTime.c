#include "MyLib/headers/treePrint.h"
#include "MyLib/headers/occTab.h"
#include "MyLib/headers/mergeSort.h"
#include "MyLib/headers/matSum.h"

#include "MyLib/headers/functions.h" 

int* (*func_ptr[5])(int n) = {occTab, matSum, treePrint, treePrintRec, mergeSort};

int main() {

    int option, i, n, step;

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

        if (option == 2){
            n = 400; 
            step = 50;
        }
        else{
            n = 1000; 
            step = 100;
        }

        i = 1;
        while(i<n){
            run(func_ptr[option-1], i); 
            run(func_ptr[option-1], i); 
            run(func_ptr[option-1], i);
            run(func_ptr[option-1], i); 
            printf("\n\n");
            if (i==1)
                i--;
            i+=step;
        }

    }   
    
    return 0;

}
