# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

#define u8 uint8_t

union Empty {};

union Data {
    int i;
    float f;
    char c;
};

union Data2 {
    int i, i2, c2;
};

typedef union {
    struct {
        u8 a : 3;
        u8 b : 5;
    };
    u8 byte;
} Bits;

typedef union Date {
    int id;
    struct {
        u8 day;
        u8 month;
        u8 year;
    };
} Date;

union Data get_data(void) {
    union Data d;
    d.i = 42;
    return d;
}

union Foo { int x; float y; } func(void) {
    union Foo foo;
    foo.x = 'a';
    return foo;
}

union FirstLevel {
    union SecondLevel {
        int a;
        float b;
    } second;
};

// union {}; // Error

union foo { int i; double d; };

int main(void) {
    // union {}; // Error

    // A union is a special user-defined type in C where all members share the same memory location.
    union Data data;
    data.i = 10;    // sets integer
    data.f = 3.14;  // now float overwrites the memory
    union Data data_copy = data;

    Bits x;
    x.byte = 0xAB;
    printf("%u %u\n", x.a, x.b);

    union Date records[] = {
        0, 2023, 1, 1,
        1, 2024, 2, 2, // trailing comma
    };

    // Anonymous unions in stack storage:
    union {
        int x;
        float y;
    } anon_union = { .x = 100 };

    union {
        int x;
        float y;
    } another_union;
    another_union.y = 5.5f;

    // Memory allocation for union:
    union Data* pData = malloc(sizeof(union Data));
    pData->c = 'A';
    free(pData);

    // Error:
    // union SecondLevel sl;
    // sl.a = 20;
    // union FirstLevel fl;
    // fl.second = sl;

    //
    int x = 42;
    double y = 3.14;

    union foo u;

    u = (union foo)x;
    u = (union foo)y;

    return 0;
}