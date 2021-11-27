#include "../headers/functions.h"
#include "../headers/treePrint.h"    

int isEmpty() {
   return top == -1;
}

int isFull() {
   return top == MAXSIZE;
}

int pop() {
   int data = 0;
   if(!isEmpty()) {
      data = stack[top];
      top = top - 1;  
   } 
   return data;
}

void push(int data) {
   if(!isFull()) {
      top = top + 1;   
      stack[top] = data;
   }
}

void clearTree(node root){
    if (!root)
        return;
    clearTree(root->left); 
    free(root);
    clearTree(root->right);
}

node createNode(int x){
    node root = (node) malloc(sizeof(node0));
    root->left = NULL;
    root->right = NULL;
    root->val = x;
    return root;
}

node add(node root, int x){

    if(!root) {
        return createNode(x);
    } 

    if(x < root->val) {
        root->left = add(root->left, x);
    }
    else{
        root->right = add(root->right, x);
    }
    return root;

}

void printTree(node root){

    while (root || !isEmpty()){ 
        count++;
        while(root){ // h = Log2(n) 
            count++;
            push((int)root);
            root = root->left;
        }
        root = (node) pop();
        //printf("%d \t", root->val);
        root = root->right;
    }
    // Version 2
	/*while (1){
        count++;
        if  (root){
            push((int)root);
            root = root->left;
        }
        else{
            if (isEmpty())
                return;
            else{
                root = (node) pop();
                printf("%d \t", root->val);
            }
            root = root->right;
        }
	}*/


}

void printTreeRec(node root){ //O(n)
    if (!root)
        return;
    count++;
    printTreeRec(root->left); 
    //printf("%d \t", root->val);
    printTreeRec(root->right);
}

int* treePrint(int n){
    // Creation
    int i;
    node root = NULL;
    srand(time(NULL));

    for(i=0; i<n; i++){
        root = add(root, randnum(Min, Max));
    }

    // Print
    uint64_t time = ns();
    printTree(root);
    time = ns()-time;
    clearTree(root);

    int* ret = (int*) malloc(sizeof(int) * 2);
    *ret = time;
    *(ret+1) = count;
    return ret;
}

int* treePrintRec(int n){
    // Creation
    int i;
    node root = NULL;
    srand(time(NULL));

    for(i=0; i<n; i++){
        root = add(root, randnum(Min, Max));
    }

    // Print
    uint64_t time = ns();
    printTreeRec(root);
    time = ns()-time;
    clearTree(root);

    int* ret = (int*) malloc(sizeof(int) * 2);
    *ret = time;
    *(ret+1) = count;
    return ret;
}
