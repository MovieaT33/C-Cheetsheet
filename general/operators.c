#include <stdio.h>
#include <limits.h>

int main(void) {
    // Note: if operands are of different types, C applies "usual arithmetic conversions".

    int a = +5, b = -2, c;

    // Arithmetic operators:
    c = a + b /* -> (int)a + (int)b; */;
    c = a -
        b;
    c = a * b;
    c = a / b;
    c = a % b;
    a++, a ++;
    // a + +; // Error
    ++a;
    + + a;
    ++ a;

    b--;
    b --;
    // b - -; // Error
    --b;
    - -b;
    -- b;

    // Pointers (`&`, `*`) and their arithmetic.
    int b, a = &b;
    // int c = *b; // Error

    // (...):
    c = (a + b) * 8;

    // `i++` VS `++i` example:
    int i = 0;
    c = i++; // c = 0, i = 0
    i++;     // i = 1

    i = 0;
    c = ++i; // c = 1, i = 1

    c /= 0; // UB
    c %= 0; // UB

    // Logical operators:
    int x = 1, y = 0;
    printf("x && y = %d\n", x && y);    // Logical AND
    printf("x || y = %d\n", x || y);    // Logical OR
    printf("!x = %d\n", !x);            // Logical NOT

    // Bitwise operators:
    int mask = 0b1010;
    printf("mask & 0b1100 = %d\n", mask & 0b1100);  // Bitwise AND
    printf("mask | 0b1100 = %d\n", mask | 0b1100);  // Bitwise OR
    printf("mask ^ 0b1100 = %d\n", mask ^ 0b1100);  // Bitwise XOR
    printf("~mask = %d\n", ~mask);                  // Bitwise NOT
    printf("mask << 1 = %d\n", mask << 1);          // Left shift
    printf("mask >> 1 = %d\n", mask >> 1);          // Right shift

    // Compound assignment operators:
    int val = 10;
    val += 5;
    val -= 3;
    val *= 2;
    val /= 4;
    val %= 3;
    val &= 1;
    val |= 2;
    val ^= 3;
    val <<= 1;
    val >>= 1;

    // a >> -1; // UB
    // b << -1; // UB

    int a = -1;
    int b = a >> 1; // Arithmetical or logical shift?

    // Comparison operators:
    a = 5; b = 2;
    printf("a == b -> %d\n", a == b);
    printf("a != b -> %d\n", a != b);
    printf("a > b -> %d\n", a > b);
    printf("a < b -> %d\n", a < b);
    printf("a >= b -> %d\n", a >= b);
    printf("a <= b -> %d\n", a <= b);

    // Comma operator:
    int num;
    c = (num = 5, printf("Hello\n"), num + 3); // 8

    // Special:
    int cool_var = 1;
    if (cool_var =! 0) return 1; // if (cool_var = !0)

    size_t n = 10;
    while (n --> 0) // `while (n-- > 0)`
        printf("%d\n", n);

    while (n <-- n);

    1 && printf("Printed because 1 is true\n");
    0 && printf("Not printed because 0 is false\n");
    1 || puts("I will not be printed either\n");
    int status = 0 || puts("But I will!\n");

    int var = ~~10;
    var = -~var;  // 11
    var = ~-var;  // 10
    int minus_var = ~var + 1;

    if (var) { }  // if (var != 0)

    x = 0b101100;
    x &= x - 1;   // 0b101000

    if (x && !(x & (x - 1))) { }

    int abs = (x ^ (x >> 31)) - (x >> 31);

    // XOR-swap:
    int a = 0b101, b = 0b010;
    a ^= b; // a = 101 ^ 010 = 111
    b ^= a; // b = 010 ^ 111 = 101
    a ^= b; // a = 111 ^ 101 = 010

    a ^= b ^= a;

    x = (5 && 2); // x = 1 int not bool

    // `a[b]` -> `*(a + b)`

    // Buffer overflow and underflow:
    int i = INT_MAX;
    i += 1; // Overflow, UB
    unsigned j = 0;
    j -= 1;

    //
    printf("%zu\n", _Alignof(double));

    return 0;
}