#ifndef SORT_H
#define SORT_H

#include "functions.h"

typedef struct node1* list;
struct node1{
    int val;
    list next;
}node1;

list newNode(int x);
void clearList(list head);
void printList(list head);
list createList(int n);
int lengthList(list head);
int midList(list head);
list* devideList(list head);
list mergeList(list head1, list head2);
list sort(list head);
uint64_t mergeSort(int n);

#endif
