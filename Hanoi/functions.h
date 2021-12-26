#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

#define DISKS 50 // Max number of disks
#define t 3 // Max number of towers

int towers[DISKS][t];
int i, j, disks;
uint64_t time;
static int step=1;

uint64_t ns(); // To calculate the time

void print(); // Print the matrix
void create(); // Initialise the values
int get_location(int disk, int tower); // Get the index of the disk located in the tower
int first_zero(int tower); // Get the index of the first free spot (first zero) in the tower
void move(int disk, int source, int destination); // Moving the disk from one tower to another
void hanoifun(int n, int source, int destination, int spare); // Solve the game

int verify(int source, int destination); // Verification algorithm
