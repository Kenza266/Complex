#ifndef TREE_H
#define TREE_H

#include "functions.h"

#define MAXSIZE 100

typedef struct node0* node;
struct node0{
    int val;
    node left;
    node right;
}node0;

int stack[MAXSIZE];     
static int top = -1;            

int isEmpty();
int isFull();
int pop();
void push(int data);
void clearTree(node root);
node createNode(int x);
node add(node root, int x);
void printTree(node root);
void printTreeRec(node root);
uint64_t treePrint(int n);
uint64_t treePrintRec(int n);

#endif
