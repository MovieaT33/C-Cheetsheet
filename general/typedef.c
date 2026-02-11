/* Syntax:
typedef existing_type new_type_names;
existing_type typedef new_type_names;

Typedef can be used with any data type.
*/

// 1. Usage of typedef with basic types:
unsigned typedef char byte;
typedef unsigned int u32;

// 2. Usage of typedef with array:
typedef char CharArray[50],
             char_array[50];

// 3. Usage of typedef with struct:
struct Foo {
    u32 a;
} typedef FooStruct, *foo_struct, fs;

// 4. Usage of typedef with union:
typedef union Foo {
    int b;
    float c;
    FooStruct d;
} FooUnion, *foo_union, fu;

// 5. Usage of typedef with enum:
typedef enum {
    RED,
    GREEN,
    BLUE
} Color, *color, c;

// 6. Usage of typedef with pointer:
typedef int* IntPtr, int_ptr;

// 7. Usage of typedef with function pointer:
typedef void (*FuncPtr)(int, float),
             (*func_ptr)(int, float);

int main(void) {
    FooUnion foo_union_2;
    foo_union_2.b = 10;

    // 9. Usage of typedef with function:
    typedef double fun_t(double);
    fun_t sin, cos, sqrt;

    int z = sin(0.5); // UB

    return 0;
}