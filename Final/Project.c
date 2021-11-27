#include "MyLib/headers/treePrint.h"
#include "MyLib/headers/occTab.h"
#include "MyLib/headers/mergeSort.h"
#include "MyLib/headers/matSum.h"

#include "MyLib/headers/functions.h" 

int* (*func_ptr[5])(int n) = {occTab, matSum, treePrint, treePrintRec, mergeSort};

int main() {

    int option, n;

    while (1){

        option = 0;

        printf("\n\nSelect one algorithm\n");
        printf("%d: Quit\n", option++);
        printf("%d: Calculating the number of occurrences of a digit in an array\n", option++);
        printf("%d: Matrix sum\n", option++);
        printf("%d: Inorder display of a binary search tree\n", option++);
        printf("%d: Inorder display of a binary search tree (Recursive)\n", option++);
        printf("%d: Merge sort of an array\n\n", option++);

        printf("\nEnter algorithm number: ");
        scanf("%d", &option);

        if (!option) 
            break;

        printf("\nEnter space size: ");
        scanf("%d", &n);

        if (option == 2) 
            printf("\nSpace size is %dx%d\n", n, n);
        else
            printf("\nSpace size is %d\n", n);
        
        
        run(func_ptr[option-1], n); 

        printf("Time complexity: ");

        switch (option){
            case 1: printf("O(n)"); break;
            case 2: printf("O(n^2)"); break;
            case 3: printf("O(n)"); break;
            case 4: printf("O(n)"); break;
            case 5: printf("O(n log2(n))"); break;
        };

    }   
    
    return 0;

}
