#ifndef TREE_H
#define TREE_H

#include "functions.h" 

#define MAXSIZE 2000

typedef struct node0* node;
struct node0{
    int val;
    node left;
    node right;
}node0;

node stack[MAXSIZE];     
static int top = -1;            

int isEmpty();
int isFull();
node pop();
void push(node data);
void clearTree(node root);
node createNode(int x);
node add(node root, int x);
void printTree(node root);
void printTreeRec(node root);
int* treePrint(int n);
int* treePrintRec(int n);

#endif
