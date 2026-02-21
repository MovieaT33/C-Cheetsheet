#include <stddef.h>

/* Syntax (like a function call, but `sizeof` is an operator):
sizeof(type_or_expression)
sizeof expression
*/

struct Example {
    int a;
    double b;
};
// sizeof(Example) != sizeof(int) + sizeof(double) due to potential padding

union ExampleUnion {
    int a;
    double b;
    char c;
};
// sizeof(ExampleUnion) == max(sizeof(int), sizeof(double), sizeof(char))

enum ExampleEnum {
    ENUM_VAL1,
    ENUM_VAL2,
    ENUM_VAL3
};

int main(void) {
    // `size_t` is the type returned by `sizeof`:
    size_t a = sizeof(int);
    int b = sizeof a == a;
    int c = sizeof(b += 2) == 4;
    // b = 1, c = 1

    size_t c = sizeof('d'); // 'd' -> (int)100 -> 4 bytes
    size_t s = sizeof("Hello");

    // Using sizeof with variables:
    int x;
    double y;

    printf("%zu, %zu\n", sizeof(x), sizeof x);
    printf("%zu, %zu\n", sizeof(y), sizeof y);

    // Using sizeof with expressions:
    printf("%zu\n", sizeof(x + 1.0)); // expression results in double

    // Using sizeof with string literals:
    printf("%zu\n", sizeof("Hello")); // includes null terminator

    // Using sizeof with compound literals:
    printf("%zu\n", sizeof((int[]){1, 2, 3, 4, 5})); // array of 5 integers

    // Using sizeof with arrays:
    int arr[10];
    printf("%zu, %zu\n", sizeof(arr), sizeof arr);

    // Using sizeof with nested arrays:
    int nestedArr[2][3][4];
    printf("%zu\n", sizeof(nestedArr));

    // Using sizeof with struct:
    struct Example ex;
    printf("%zu, %zu\n", sizeof(ex), sizeof ex);

    // Using sizeof with union:
    union ExampleUnion exu;
    printf("%zu, %zu\n", sizeof(exu), sizeof exu);

    // Using sizeof with enum:
    enum ExampleEnum ee;
    printf("%zu, %zu\n", sizeof(ee), sizeof ee);

    // Using sizeof with pointer types:
    printf("%zu\n", sizeof(int*));

    int arr2D[3][4];
    int *ptr = arr2D[0];
    printf("%zu\n", sizeof(arr2D) / sizeof(arr2D[0])); // number of rows
    printf("%zu\n", sizeof(ptr)); // size of pointer

    // Using sizeof with typedef:
    typedef struct {
        char c;
        double d;
    } TypedefExample;
    printf("%zu\n", sizeof(TypedefExample));

    // Using sizeof with void type is not allowed:
    // printf("%zu\n", sizeof(void));

    // Using sizeof with incomplete types is not allowed:
    // struct Incomplete;
    // printf("%zu\n", sizeof(struct Incomplete));

    // Using sizeof with bit-fields is not allowed:
    struct BitField {
        unsigned int a : 3;
        unsigned int b : 5;
    };
    // printf("%zu\n", sizeof(((struct BitField *)0) -> a));

    // Using sizeof with function types is not allowed:
    // printf("%zu\n", sizeof(int(void)));

    // Using sizeof with flexible array members is not allowed:
    struct FlexibleArray {
        int len;
        int arr[];
    };
    printf("%zu\n", sizeof(struct FlexibleArray));

    // Using sizeof with variable length arrays is allowed:
    // int n = 10;
    // int varArr[n];
    // printf("%zu\n", sizeof(varArr));

    // Using sizeof in switch cases:
    int var = 5;
    short var_2 = 10;

    switch (var) {
        default: break;
        case sizeof var:
            break;
        case sizeof var_2:
            break;
    }

    int o = 5;
    sizeof(int[++o]); // o = 6
    printf("%d", o);

    int delta = 10;
    int gamma[delta];
    int y=sizeof(gamma);     // 3 * sizeof(int) = 40
    int z=sizeof(gamma + 0); // sizeof(int*) = 8 (on 64-bit)
}