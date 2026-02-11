#include <stddef.h>

void copy_array(size_t n, const int *restrict src, int *restrict dst) {
    for (size_t i = 0; i < n; ++i)
        dst[i] = src[i];
}

void sum3_arrays(int a[restrict static 100],
                 int b[restrict static 100],
                 int c[restrict static 100]) {
    // `restrict` indicates that the arrays do not overlap.
    for (int i = 0; i < 100; ++i)
        a[i] = b[i] + c[i];
}

int main(void) {
    int a = 100'000;

    int *restrict b = &a;
    int *restrict c = &a;   // Error
    int *d          = &a;   // OK

    // int e[restrict 10];  // Error

    return 0;
}