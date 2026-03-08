#include <stdlib.h>

#include <stdbool.h>

int sum(a, b)
int a, b;
{
    return a + b;
}

// int sum(int a, b) { // Error: parameter `b` has no type

/*
int multiply(int a, b) { // Error
    return a * b;
}
*/

int zero() {} // Returns `0` by default.

/* `void` (as function argument) indicates that the function cannot take any arguments.
   An empty argument list means that the function can take any number of arguments. */

// Global-level function definitions
int inner(void) {
    return 42;
}

// inner(); // Error

// int inner(void) {}  // Error

static int another_func() {return 8;}

int* foo(void) {
    int k = 800'900; // Stack
    return &k;
}

int *bar() {static float g = 1.5; return &g;}

void stack(int n) {
    int arr[n]; // GCC extension: VLA (Variable Length Array)
}

const int *some_func(void)
{
    int *i_want_some_memory = malloc(sizeof(int));
    return i_want_some_memory;
}

bool *foo_bar(void) {
    static const bool h = false;
    return &h;
}

void module__Foo(int a[10]) {
    sizeof(a); // sizeof(int*) -> sizeof(pointer) -> 4 bytes (64-bit)
}

void module__Bar(int g(double)); // -> void f(int (*g)(double));

void my_log(const char *fmt, ...)
    __attribute__((format(printf, 1, 2)));

#include <stdio.h>

void module__VAL(int n, int (*a)[n]) {
    for (int i = 0; i < n; i++)
        printf("%d ", (*a)[i]);
}

int main(void) {
    // Local-level function definitions
    int local_inner() {   // Compilation error, but in GCC is OK
        return;
    }

    int result = local_inner(); // call the global or local function

    another_func() = 777;   // Error

    *foo() = 100;   // Error. `k` (stack) has destroyed

    *bar() = 7.8;   // OK

    *some_func() = 9;   // OK

    *foo_bar() = true;  // Error. Const

    do_not_work();

    int i = 1, j = 2;
    sum(i++, j++); // UB

    my_log("Value: %d\n", 42);

    return result;
}

void do_not_work() {
    local_inner();
}

/* Error code:
int main(void) { func(); }

void func() { }
*/