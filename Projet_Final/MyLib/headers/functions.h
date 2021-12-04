#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MIN 0
#define MAX 500
#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

#if defined(__linux) //select linux timer
#define HAVE_POSIX_TIMER
#include <time.h>
#ifdef CLOCK_MONOTONIC
#define CLOCKID CLOCK_MONOTONIC
#else
#define CLOCKID CLOCK_REALTIME
#endif
#elif defined(__APPLE__) //select apple timer
#define HAVE_MACH_TIMER
#include <mach/mach_time.h> 
#elif defined(_WIN32) //select windows timer
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

int count;

uint64_t ns();
void run(int* (*f)(int), int n);

#endif
