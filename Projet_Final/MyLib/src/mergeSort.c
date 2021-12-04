#include "../headers/functions.h"
#include "../headers/mergeSort.h"

list newNode(int x){
    list tmp = (list) malloc(sizeof(node1));
    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}

void clearList(list head){
    if (!head)
        return;
    clearList(head->next);
    free(head);
}

void printList(list head){
    while(head){
        printf("%d-->", head->val);
        head = head->next;
    }
    printf("\n");
}

list createList(int n){

    list head = NULL, tmp;
    int i;

    for (i=0; i<n; i++){
        tmp = newNode(randnum(MIN, MAX));
        tmp->next = head;
        head = tmp;
    }
    return head;

}

int lengthList(list head){
    if (head)
        return lengthList(head->next) + 1;
    return 0;
}

int midList(list head){
    return (int)ceil((float)lengthList(head)/2);
}

list* divideList(list head){
    
    if (!head)
        return NULL;

    list* ret = (list*) malloc(sizeof(list) * 2);
    *ret = head;
    int mid = midList(head) - 1;

    while(mid>0){
        head = head->next;
        mid--;
    }
    *(ret+1) = head->next;
    head->next = NULL;

    return ret;

}

list mergeList(list head1, list head2){

    if (!head1)
        return head2;
    if (!head2)
        return head1;
    count++;
    if (head1->val < head2->val){
        head1->next = mergeList(head1->next, head2);
        return head1;
    }
    else{
        head2->next = mergeList(head1, head2->next);
        return head2;
    }

}

list sort(list head){

    if(!head->next)
        return head;
    count++;
    list* ret = divideList(head);
    return mergeList(sort(*ret), sort(*(ret+1)));

}

int* mergeSort(int n){

    srand (time(NULL));

    list head = createList(n);
    
    //printf("\nThe list:\t");
    //printList(head);

    uint64_t time = ns();
    head = sort(head);
    time = ns()-time;

    printf("The list is now sorted\n");
    //printList(head);

    clearList(head);
    
    int* ret = (int*) malloc(sizeof(int) * 2);
    *ret = time;
    *(ret+1) = count;

    return ret;
}
