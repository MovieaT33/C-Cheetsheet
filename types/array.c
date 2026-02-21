#define LEN 10
#define ARRAY_LEN(a) (sizeof a / sizeof a[0])

#include <stdio.h>
#include <stdlib.h>

void foo(int ints[]) {} // Equivalent to `foo(int *ints)`.

typedef void func_typedef(void);

void some_func(void) {}

struct FlexibleArray {
    int len;
    int data[];         // Flexible array member (C99 feature).
};

int global_level_arr[] = {1, 2, 3, 4, 5};
int arr_2[];  // Warning: array 'arr_2' assumed to have one element.

int main(void) {
    func_typedef funcs_arr[1] = {some_func}; // Error: array of functions is not allowed.

    // 1. One-dimensional array:
    char empty[] = {};
    // char error_arr[] = empty; // Error
    char empty2[0] = {};

    int var = 5;
    int numbers[5] = {1, 2, 3, 4, var,};
    numbers == &numbers[0];             // numbers[i] == *(numbers + i)
    printf("%d", *numbers);

    // numbers = {0, 1, 2, 3, 4}; // Error

    // 2. Array without explicit size (compiler infers size from initializer):
    int a0[] = {1, 2, 3};
    a0[0] = 10;             // modify first element
    a0[10] = 20;            // UB: out-of-bounds

    // 3. Fixed-size array:
    int a[10];
    sizeof a;       // sizeof(int) * 10
    sizeof &a;      // 8 (on 64-bit)

    int arr[] = {1, 2, 3};
    int *b = &arr;
    sizeof b;       // 8 (on 64-bit)

    // 4. Two-dimensional array:
    int matrix[2 + 0][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    matrix[1][4 / 2] = 7;

    // 5. Flattened initialization of multi-dimensional array:
    int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // 6. Multi-dimensional array:
    int arr4D[2][2][2][3] = {
        {
            {
                {1, 2, 3},
                {4, 5, 6}
            },
            {
                {7, 8, 9},
                {10, 11, 12}
            }
        },
        {
            {
                {13, 14, 15},
                {16, 17, 18}
            },
            {
                {19, 20, 21},
                {22, 23, 24}
            }, // trailing comma
        }
    };

    // 7. Variable-length array (VLA):
    int b[LEN] = {10};
    (ARRAY_LEN(b) == LEN) && printf("True\n");

    int c = rand();
    // int d[c];    // Error

    // 8. Compound literals (C99 feature):
    foo((int[]){1, 2, 3});
    int ints[] = (int[]){1, 2};

    // 9. Designated initializers for arrays (C99 feature):
    int foo2[][2] = {
        [0] = {'H', 'e'},
        ['d'] = {1, 2},     // Index = 100 ('d' in ASCII).
    };

    // 10. Unusual array tricks:
    int data[100];
    'd'[data] = 42;     // equivalent to data[100] = 42
    100[data] = 24;     // equivalent to data[100] = 24

    // 11. Incorrect array:
    // int foo_negative[-10];   // UB: negative size

    // 12. Flexible array member usage:
    struct FlexibleArray *flex = malloc(sizeof(struct FlexibleArray) + sizeof(int) * 5);
    flex->len = 5;
    for (int i = 0; i < flex->len; ++i)
        flex->data[i] = i * 10;

    *(flex->data + 2) = 10;

    // 13. Partial initialization with zero:
    int zeros[10] = {1, 2, 3};
    /*
     * zeros[3 -> 9] = 0;
     */

    int trash[10];
    /*
     * trash[0 -> 9] = ?;
     */

    // 13. Array and pointers:
    int a = 5, b = 8, c = 34, d = 98;
    int *pointers[] = {&a, &b, &c, &d};
    int a_copy = *pointers[0];

    // 14. Array and function pointers:
    void (*funcs[])() = {some_func};
    funcs[0]();

    /* Or:
     * void (*funcs[1])() = {&some_func};
     * void (*funcs[2])() = {&some_func}; printf("%d", funcs[2]); // 0
     */

    // Error:
    // void *functions[]() = {some_func};
    // void (*functions)[]() = funcs;

    // But:
    void (**functions)() = funcs;

    // 15. Null terminated array:
    unsigned char null_terminated[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, NULL}; // Or `0` instead of `NULL`
    for (register long long i = 0; null_terminated[i]; ++i);

    // 16. GCC extension: range initialization (not standard C):
    int gcc[] = {[0 ... 10] = 70, 3, [11 ... 12] = 4};
    int gcc2[20] = {[9] = 2};

    // foo({1, 2, 3}); // Error

    return 0;
}