#include <stdio.h>

// `.rodata` section
const int const_var = 2e+4;

// Undefined section
constexpr int constexpr_var = 3e-2;

// `.data` section
int global_a = {}; // `{}` is a empty initializer which initializes a variable to zero
int global_b = 10 + 10;
// int global_3 = global_2;   // Error
// int global_4 = const_var;  // Error
int global_5 = constexpr_var;

// auto int auto_var;         // Error
// register int reg;          // Error

int main(void) {
    // Statements:

    /* 0. Type declaration (warning):
    <type>;
    */

    char;
    short;
    int;
    long;
    long long;

    /* 1. Variable declaration:
    <type> <name>;
    */

    int a; // Stack storage
    a;     // Statement without any effects
    printf("%d", a); // UB

    // undefined; // Error: `undefined` is not declared

    /* 2. Variable declaration + assignment:
    <name> = <value>;
    */

    int B$dollar;
    (B$dollar = 10);
    int (café) = {20, 50}, αβγ = café;

    /* 3. Variable declaration:
    <type> <name> = <value>;
    */

    int _C = { 15e8 };

    /* 4. Multiple declarations:
    <type> <name1>, <name2>, ... <nameN>;
    */

    int d, e, f;

    /* 5. Multiple initializations:
    <type> <name1> = <value1>, <name2> = <value2>, ... <nameN> = <valueN>;
    */

    int _g = 10, h__ = 5, __K__ = 3;
    // int a, b = 1, 2; // Error

    /* 6. Mixed declarations + initializations:
    <type> <name1>, <name2> = <value2>, <name3>;
    */

    int l, m = 20, n;

    /* 7. Reassignment of variable:
    <name> = <new_value>;
    */

    n = 100;

    /* 8. Chained assignments with name:
    <name1> = <name2> = <name3>;
    */

    l = m = n;

    /* 9. Chained assignments with value:
    <name1> = <name2> = <name3> = <value>;
    */

    l = m = n = 50;
    // l = 10 = 20; // Error

    // 10. Names:

    // 10.1 Valid names:
    int my_variable = 100;
    int _temp = 50;
    int var123 = 30;

    // 10.2 Invalid names:
    // int 1stVar = 10;
    // int my-var = 20;
    // int float = 30;
    // int var!able = 40; 

    // 11. Using variables in expressions and statements:
    int num;
    int bar = (num = 7, num += 8, num - 3); // bar = 12

    // 12. Invalid use of variable declaration in expression:
    // int foo = (int bar = 5, bar + 10); 

    // 13. Assignment within statements:
    int foo;

    // 13.1. `if`:
    if ((foo = 5) > 2) return 0;
    if (foo -= 7) return 2;

    // 13.2. `while`:
    while ((foo = 3) < 5);

    // 13.3. `switch`:
    switch (foo = 2) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }

    // 13.4. `do / while`:
    do ; while ((foo = 4) < 10);

    // 14. Ternary operator:
    foo = (foo = 1) ? 10 : 20;

    // 15. Special:

    // 15.1. Compiler standard defaults (to `int`):
    signed var;
    unsigned var_2;

    short short_var         = 1;
    long long_var           = 2;
    long long long_long_var = 3;

    // 15.2. Old compiler standard defaults (to `int`):
    /*
    auto auto_var_2;
    extern ext;
    const con;
    register reg_2;
    static stat_var;
    volatile vol;
    */

    // 15.3. GCC attributes:
    int var_3 __attribute__((section(".mysection"))) = 42;
    int var_4 __attribute__((aligned(16)));
    int var_5 __attribute__((common));
    int var_6 __attribute__((unused)) = 5;
    int var_7 __attribute__((used)) = 10;
    int var_8 __attribute__((visibility("hidden")));
    int var_9 __attribute__((deprecated));
    void cleanup_func(int *p) {
        printf("Cleanup: %d\n", *p);
    }
    int var_10 __attribute__((cleanup(cleanup_func))) = 123;
    int var_11 __attribute__((may_alias)) = 99;
    const int var_12 __attribute__((const)) = 50;

    // 16. Initialization with itself (UB):
    int a = a;
    int b = b + 1;

    /* See all GCC variable attributes:
     * https://gcc.gnu.org/onlinedocs/gcc-13.1/gcc/Variable-Attributes.html
     * https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Variable-Attributes.html#Variable-Attributes
     */

    // `thread_local`

    if (-1 < 1U) // false

    return 1;
}