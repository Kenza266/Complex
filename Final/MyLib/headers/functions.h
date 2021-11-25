#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define RANGE 500

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

static int count = 0;

static uint64_t ns();

void run(uint64_t (*f)(int), int n);
int random(int range);

#endif
