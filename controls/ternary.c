#include <stdio.h>

#define NUM 50

char bool_1 = NUM ? 1 : 0;          // bool_1 = 1
// char bool_2 = bool_1 ? 2 : 0;    // error: initializer element is not constant

constexpr char bool_3 = NUM ? 3 : 0; // bool_3 = 3
char bool_4 = bool_3 ? 4 : 0;        // bool_4 = 4

enum {
    BOOL_5 = (NUM ? 1 : 0)
};

short foo(void)
{
    return 5;
}

int main(void)
{
    short a = 10, b = 20, c = a > b ? a, foo() : b; // c = 20

    char* a_type = (a % 2 == 0) ? "even" : "odd";

    char* grade =
        (a >= 90) ? "A" :
        (a >= 75) ? "B" :
        (a >= 60) ? "C" : "F";

    // GCC extension
    int d = a ?: b; // int d = a ? a : b;

    long e = a ?: e; // int e = a ? a : e;
}