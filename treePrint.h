#include "functions.h"

#define MAXSIZE 100

int stack[MAXSIZE];     
int top = -1;            

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

typedef struct node0* node;
struct node0{
    int val;
    node left;
    node right;
}node0;

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
        while(root){ // h = log2(n)
            push((int)root);
            root = root->left;
        }
        root = (node) pop();
        printf("%d \t", root->val);
        root = root->right;
    }
    // Version 2
	/*while (1){
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

void printTreeRec(node root){
    if (!root)
        return;
    printTreeRec(root->left); 
    printf("%d \t", root->val);
    printTreeRec(root->right);
}

uint64_t treePrint(int n){
    // Creation
    int i;
    node root = NULL;
    srand(time(NULL));

    for(i=0; i<n; i++){
        root = add(root, random(RANGE));
    }

    // Print
    uint64_t time = ns();
    printTree(root);
    time = ns()-time;
    clearTree(root);
    return time;
}

uint64_t treePrintRec(int n){
    // Creation
    int i;
    node root = NULL;
    srand(time(NULL));

    for(i=0; i<n; i++){
        root = add(root, random(RANGE));
    }

    // Print
    uint64_t time = ns();
    printTreeRec(root);
    time = ns()-time;
    clearTree(root);
    return time;
}
