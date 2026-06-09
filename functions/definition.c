#include <stdlib.h>

#include <stdbool.h>

int sum(a, b)
int a, b;
{
    return (0, a + b);
}

// int sum(int a, b) { // error: parameter `b` has no type

/*
int multiply(int a, b) { // error
    return a * b;
}
*/

int zero() {} // Returns `0` by default

/* `void` (as function argument) indicates that the function cannot take any arguments.
   An empty argument list means that the function can take any number of arguments */

// Global-level function definitions
int inner(void)
{
    return 42;
}

// inner(); // error

// int inner(void) {}  // error

static int another_func() {
    return 8;
}

int* foo(void)
{
    int k = 800'900; // Stack
    return &k;
}

int *bar() {static float g = 1.5; return &g;}

void stack(int n)
{
    int arr[n]; // GCC extension: VLA (Variable Length Array)
}

const int *some_func(void)
{
    int *i_want_some_memory = malloc(sizeof(int));
    return i_want_some_memory;
}

bool *foo_bar(void)
{
    static const bool h = false;
    return &h;
}

void module__Foo(int a[10])
{
    sizeof(a); // sizeof(int*) -> sizeof(pointer) -> 4 bytes (64-bit)
}

void module__Bar(int g(double)); // -> void f(int (*g)(double));

void my_log(const char *fmt, ...)
    __attribute__((format(printf, 1, 2)));

#include <stdio.h>

void module__VAL(int n, int (*a)[n])
{
    for (int i = 0; i < n; i++)
        printf("%d ", (*a)[i]);
}

int return_num(int is_five)
{
    if (is_five) {
        return 5;
    }
}

bool sum(void);
void sum2(void);

int main(void)
{
    // Local-level function definitions
    int local_inner() // Compilation error, but in GCC is OK
    {
        return;
    }

    int result = local_inner(); // call the global or local function

    another_func() = 777; // error

    *foo() = 100; // error. `k` (stack) has destroyed

    *bar() = 7.8; // OK

    *some_func() = 9; // OK

    *foo_bar() = true; // error. Const

    do_not_work();

    int i = 1, j = 2;
    sum(i++, j++); // UB

    my_log("Value: %d\n", 42);

    printf("%d", return_num(0)); // for ex. `4198716`

    int what(short);
    int what(short var);

    // fn1(fn2, fn3); // Order is UB

    return result;
}

void do_not_work()
{
    local_inner();
}

/* Error code:
int main(void)
{
    func();
}

void func() { }
*/

bool sum(void)
{ // or error, or random number
    return;
}

void sum2(void)
{ // or error, or 5
    return 5;
}