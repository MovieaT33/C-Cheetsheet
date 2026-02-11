#include <stddef.h>
#include <stdio.h>

int main(void) {
    // 1
    int *ptr = NULL;
    *ptr = 42; // Segmentation fault

    // 2
    int arr[3] = {1, 2, 3};
    int val = arr[5]; // UB: accessing array out of bounds

    // 3
    char *str = "Hello"; // Read-only string literal (`.rodata` section)
    str[0] = 'h';        // String literals are read-only.

    // 4
    *(int*)0 = 5;        // Dereferencing NULL pointer.

    // 5
    int *var = 0x7fffff123;
    *var = 10;

    return *var;
}