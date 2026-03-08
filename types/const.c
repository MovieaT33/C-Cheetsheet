#include <stddef.h>

inline void sum(int a[1024],
                int b[const 1024]) {
    for (int i = 0; i < 1024; ++i) a[i] += b[i];
}

int main(void) {
    const int DAYS_IN_WEEK = 7;
    // DAYS_IN_WEEK = 8;        // Error

    // Constant to pointer:
    const int x = 5;
    int *ptr = &x;
    *ptr = 10;                      // Error
    ptr = NULL;                     // Allowed

    // Pointer to constant
    int value = 5;
    int *const constPtr = &value;
    *constPtr = 10;                 // Allowed: value = 10;
    constPtr = NULL;                // Error

    // Constant pointer to constant
    const int y = 15;
    const int *const constPtrToConst = &y;
    *constPtrToConst = 20;         // Error
    constPtrToConst = NULL;        // Error

    int z = 5;
    const int *const ptrToConst = &z;
    *ptrToConst = 10;               // Error
    ptrToConst = NULL;              // Error

    //
    int *ptrToY = (int*)&y;
    *ptrToY = 10; // UB. My host: y = 10

    exit(0);
}