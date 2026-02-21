#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define NULL ((void*)0) // standard NULL definition

// Function examples:
inline int add(int x, int y) {
    return x + y;
}

void foo(void);

int bar(void) {
    static int global = 42;
    int *addr = &global;
    return *addr = 10;
}

// Struct example:
struct Point {
    int x;
    int y;
};

// Union example:
union Data {
    int i;
    float f;
    char c;
};

// Bit-field example:
typedef struct Foo {
    int b : 2;
    int c : 6;
} BF;

int proceed(int (*func)(int, int), int x, int y)
{
    return func(x, y);
}

void f() {}

int
main(void) {
    int a = 10;

    // Pointers:
    void         *generic_ptr = &a; // generic pointer (void*)
    register int     *int_ptr = &a; // pointer to int with register storage class
    &int_ptr;                       // invalid: cannot take address of register variable

    // Pointer to char:
    char* char_ptr1;
    char *char_ptr2;    // same as above

    // Pointer to pointer:
    int d = 120;
    int *e = &d;
    int **f_ptr = &e;
    **f_ptr == 120;
    d == **f_ptr;   // True

    // Function pointers:
    int (*func_ptr)(int, int) = add;
    int (*func_ptr2)(int, int) = &add;
    int (*func_ptr_array[2])(int, int) = { add, &add };
    int result = func_ptr(3, 4);

    if (!&foo) return -1;

    // Struct pointer usage:
    struct Point p1 = {10, 20};
    struct Point *ptr = &p1;
    ptr->x = 30;                // same as (*ptr).x
    int y_val = ptr->y;         // access via pointer

    // Union pointer usage:
    union Data data;
    union Data *p_data = &data;
    p_data->i = 5;              // same as (*p_data).i

    // Bit-field usage:
    BF j = { .b = 3, .c = 8 };
    BF *p_bf = &j;
    // &j.b;    // Error: cannot take address of a bit-field.

    // Unsafe pointers:
    void (*foo)() = (void(*)())100;     // Casting integer to function pointer (unsafe)
    // foo();                           // calling is UB

    // Dynamic memory allocation:
    int *data_2 = malloc(sizeof(int) * 10);
    *(data_2 + 0) = 10;
    data_2[1] = 20;

    // Pointer declaration nuances:
    // int* first, second = &a, &a;
    /*
    Error, because
    int* a, b -> int *a, b,
    where `a` is pointer, but `b` is not.
    */

    // Array and pointer relationship:
    int arr[5] = {1, 2, 3, 4, 5};
    arr == &arr[0];  // True
    int *pArr = arr;
    pArr == &arr[0]; // True

    // String literals:
    char *str = "Hello";
    // *str = "Linux";      // Error: modifying string literal.
    str == &str[0];         // True

    char *str_2 = &"Hi"[0]; // pointer to first character of string
    sizeof *str_2;          // size of char

    // Errors:
    void a = 5;

    // Calling functions via pointers:
    void (*fp)(void) = foo;
    void (*fp)(void) = *foo;
    void (*fp)(void) = &foo;

    void (*fp)(void) = **foo;
    void (*fp)(void) = &**foo;
    void (*fp)(void) = **&**foo;
    void (*fp)(void) = &**&**&**&foo;

    foo();
    (*foo)();
    (&foo)();
    (*&foo)();

    fp();
    (*fp)();
    (*&fp)();
    (**fp)();
    (&**fp)();
    (**&**fp)();
    (*&*&*&*fp)();

    void (*fp)() = f;
    void (*fp2)() = fp + 1;

    sizeof(void); // 1
    sizeof(f);    // 1

    int variable = 10, *pointer = &variable;
    *pointer++; // increments pointer
    (*pointer)++; // increments value
}

// Second main example: function pointer with typedef.
int square(int x) {
    return x * x;
}

typedef int (*f)(int);

int main_second() {
    f func = square;
    int result = func(5);
    printf("%d\n", result);

    int variable = 10;
    int *a = &variable;
    int *sum = a + 10;
    int *sub = a - 10;

    int *a_2 = &variable;
    int ptrs_sum = a - a_2;

    /* Errors:
      * int *mul = a * 2;
      * int *div = a / 2;
      * int ptrs_sub = a + a_2;
      */

    int zoo = 5, *ptr = &zoo;

    int *array_from_10_pointers_to_int[10];
    int (*pointer_to_array_from_10_pointers)[10];

    int E;
    int *P = (int*)((char*)&E + 1);

    float F = 1;
    int *P2 = (int*)&F;
    printf("%d\n", *P2); // UB

    int *P3 = &(int){42};

    int B[3];
    int *P4 = B + 3; // ОК (one past the end rule)
    *P4 = 5;         // UB

    int X = 0x12345678;
    unsigned char *P5 = (unsigned char*)&X; // `u8` is magic type

    int *P6; { P6 = &(int){5}; }

    return 0;
}