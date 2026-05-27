// A union is a special user-defined type where all members share the same memory location

#include <stdlib.h>
#include <stdio.h>

union {}; // warning: unnamed union that defines no instances

union EmptyStruct {};

// union EmptyStruct {}; // error: redefinition of union

union Union2 {
    int a;
    float b;
    char c;
};

union Union2 get_union2(void)
{
    union Union2 u;
    u.a = 1;
    return u;
}

typedef union Union3 {
    int id;
    struct {
        char day; char month; short year;
    };
} Union3;

typedef union {
    struct {
        char a : 3;
        char b : 5;
    };
    char byte;
} Union4;

union Union5 {
    int i1, i2, i3;
};

union Union6 {
    int x;
    float y;
} func(void)
{
    union Union6 foo;
    foo.x = 'a';
    return foo;
}

union Outer {
    union Inner {
        int a;
        float b;
    } inner_union;
};

union Union7 {
    int i;
    double d;
};

union Union8 {
    union Union7 k;
};

union Union9 {
    int a;
    double b;
    // int flex[]; // error: flexible array member in union
};

union Union10 {
    int* iptr;
    float* fptr;
    char* cptr;
};

int main(void)
{
    union {}; // warning: unnamed union that defines no instances

    printf("%zu\n", _Alignof(union Union2)); // 4
    union Union2 data;
    data.a = 10;   // sets integer
    data.b = 3.14; // now float overwrites the memory
    union Union2 data_copy = data;

    // Memory allocation for union
    union Union2* allocated_data = malloc(sizeof(union Union2));
    allocated_data->c = 'A';
    free(allocated_data);

    Union2 empty = {0}; // eq. `Union2 empty = { .a = 0 };`

    union Union3 records[] = {
        0, 2023, 1, 1,
        1, 2024, 2, 2, // trailing comma
    };

    Union4 x;
    x.byte = 0xAB;
    printf("%u %u\n", x.a, x.b); // 3 4294967285

    union Inner u1;
    u1.a = 20;
    union Outer u2;
    u2.inner_union = u1;

    // Anonymous unions in stack storage
    union {
        int x;
        float y;
    } anon_union = { .x = 100, .y = 5 }; // `y` overwrites `x`

    union {
        int x;
        float y;
    } anon_union2;
    anon_union2.y = 5.5f;

    union Union7 u7;
    u7.i = 42;
    union Union8 u8;
    u8.k = u7;

    int var1 = 42;
    double var2 = 3.14;
    union Union9 u9 = (union Union9){ .a = var1 };
    u9 = (union Union9){ .b = var2 };

    int z = 42;
    union Union10 pointer_union;
    pointer_union.iptr = &z;
    printf("%d\n", *pointer_union.iptr); // 42
}