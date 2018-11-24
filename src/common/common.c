#include <stdio.h> // Import i/o

// printFlush - printf, fflush
void printFlush(const char * string) {
    printf("%s", string); // Printf
    fflush(stdout); // Flush
}