#include "../headers/functions.h"
#include "../headers/matSum.h"

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

uint64_t matSum(int n){

    srand (time(NULL));
    int A[n][n], B[n][n], C[n][n], i, j;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++){
            A[i][j] = random(RANGE);
            A[i][j] = random(RANGE);
        }

    uint64_t time = ns();
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            count++;
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    time = ns()-time;
    printf("The sum has been calculated\n");
    return time;
}
