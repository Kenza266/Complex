#include "../headers/functions.h"
#include "../headers/treePrint.h"    

static uint64_t ns() {
    static uint64_t is_init = 0;
    #if defined(__APPLE__)
        static mach_timebase_info_data_t info;
        if (0 == is_init) {
            mach_timebase_info(&info);
            is_init = 1;
        }
        uint64_t now;
        now = mach_absolute_time();
        now *= info.numer;
        now /= info.denom;
        return now;
    #elif defined(__linux)
        static struct timespec linux_rate;
        if (0 == is_init) {
            clock_getres(CLOCKID, &linux_rate);
            is_init = 1;
        }
        uint64_t now;
        struct timespec spec;
        clock_gettime(CLOCKID, &spec);
        now = spec.tv_sec * 1.0e9 + spec.tv_nsec;
        return now;
    #elif defined(_WIN32)
        static LARGE_INTEGER win_frequency;
        if (0 == is_init) {
            QueryPerformanceFrequency(&win_frequency);
            is_init = 1;
        }
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (uint64_t) ((1e9 * now.QuadPart)  / win_frequency.QuadPart);
    #endif
}

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
        printf("%d \t", root->val);
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
