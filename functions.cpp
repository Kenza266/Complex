#include "functions.h"

void run(uint64_t (*f)(int), int n){
    uint64_t time = (*f)(n);
    printf("\nTime : %llu ns\n", time);
}

int random(int range){
    return rand() % range;
}
