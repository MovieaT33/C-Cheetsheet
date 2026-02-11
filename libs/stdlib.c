#include <stdlib.h>

void cleanup() { }

int main(void) {
    atexit(cleanup);

    int *p = malloc(sizeof(int));
    free(p);
    *p = 5; // UB

    // Realloc example:
    int *arr = malloc(5 * sizeof(int));
    arr = realloc(arr, 10 * sizeof(int));
    free(arr);

    // Calloc example:
    int *zeroed = calloc(5, sizeof(int));
    free(zeroed);

    // Aligned allocation (C11 and later):
    void *aligned_ptr = aligned_alloc(16, 64); // 64 bytes aligned
    free(aligned_ptr);

    // Cast via an intermediate variable:

    // Good:
    void *vp = malloc(sizeof *ip);
    int *ip = vp;

    // Bad:
    // int *ip = (int*)malloc(sizeof(int));

    // Protection against double free:
    free(p);
    p = NULL;

    return *ip;
}