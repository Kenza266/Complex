#include "functions.h"

uint64_t ns() {
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

void print(){
    for(i=DISKS-disks; i<DISKS; i++){
        for(j=0; j<t; j++)
            printf("%d\t", towers[i][j]);
        printf("\n");
    }
    printf("-\t-\t-\n");
    printf("0\t1\t2\n\n");
}

void create(){
    for(i=0; i<DISKS; i++)
        for(j=0; j<t; j++)
            towers[i][j] = 0;

    for(i=0; i<disks+1; i++){
        towers[DISKS-i][0] = disks-i+1;
    }
}

int get_location(int disk, int tower){
    for(i=DISKS-disks; i<DISKS; i++){
        if(towers[i][tower] == disk)
            return i;
    }
    printf("Error: Disk %d not found in tower %d\n", disk, tower);
    exit(EXIT_FAILURE);
}

int first_zero(int tower){
    for(i=DISKS-1; i>=DISKS-disks; i--){
        if(towers[i][tower] == 0)
            return i;
    }
    printf("Error: Tower %d full\n", tower);
    exit(EXIT_FAILURE);
}

void move(int disk, int source, int destination){
    towers[get_location(disk, source)][source] = 0;
    towers[first_zero(destination)][destination] = disk;
    //printf("Step %d: Move disk %d from tower %d to tower %d\n", step++, disk, source, destination);
}

void hanoifun(int d, int source, int destination, int spare){
    if (d == 1){
        move(1, source, destination);
        //print();
        return;
    }
    hanoifun(d-1, source, spare, destination);
    move(d, source, destination);
    //print();
    hanoifun(d-1, spare, destination, source);
}

int verify(int source, int destination){
    for(i=DISKS-disks; i<DISKS; i++)
        if (towers[i][source] !=0 ||
            towers[i][destination] != disks-DISKS+i+1)
            return 0;
    return 1;
}
