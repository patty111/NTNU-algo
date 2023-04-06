#ifndef PROFILER_H
#define PROFILER_H

#include <time.h>

#define PROFILE_START clock_t profile_start_time = clock()

#define PROFILE_STOP do { \
    clock_t profile_end_time = clock(); \
    double profile_elapsed_time = (double)(profile_end_time - profile_start_time) / CLOCKS_PER_SEC; \
    printf("Elapsed time: %.2f seconds\n", profile_elapsed_time); \
} while(0)

#endif // PROFILER_H
