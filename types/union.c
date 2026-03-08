# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef uint8_t u8;

/* Syntax:
union {};

union <name> {
    <members>;
};

union <name> {
    <members>;
} <variables>;

union {
    <members>;
} <variables>;
*/

// union {}; // Error

union Empty {};

union Alpha {
    int i;
    float f;
    char c;
};

typedef union {
    struct {
        u8 a : 3;
        u8 b : 5;
    };
    u8 byte;
} Bits;

union Beta {
    int i, i2, c2;
};

typedef union Date {
    int id;
    struct {
        u8 day;
        u8 month;
        u8 year;
    };
} Date;

union Beta get_beta(void) {
    union Beta d;
    d.i = 42;
    return d;
}

union Gamma { int x; float y; } func(void) {
    union Gamma foo;
    foo.x = 'a';
    return foo;
}

union Delta {
    union Lambda {
        int a;
        float b;
    } second;
};

union Kilo {
    int i;
    double d;
}; union Romeo {
    union Kilo k;
};

union xray {
    int a;
    double b;
    // int flex[]; // Error: unsupported
};

int main(void) {
    // union {}; // Error

    // A union is a special user-defined type in C where all members share the same memory location.
    union Alpha data;
    data.i = 10;   // sets integer
    data.f = 3.14; // now float overwrites the memory
    union Alpha data_copy = data;

    // Memory allocation for union.
    union Alpha* pData = malloc(sizeof(union Alpha));
    pData->c = 'A';
    free(pData);

    // Bits
    Bits x;
    x.byte = 0xAB;
    printf("%u %u\n", x.a, x.b);

    // Beta
    union Beta records[] = {
        0, 2023, 1, 1,
        1, 2024, 2, 2, // trailing comma
    };

    // Anonymous unions in stack storage:
    union {
        int x;
        float y;
    } anon_union = { .x = 100, .y = 5 }; // `y` overwrites `x`

    union {
        int x;
        float y;
    } another_union;
    another_union.y = 5.5f;

    // Lambda
    union Lambda l;

    /* Error:
     * union Lambda sl;
     * sl.a = 20;
     * union Delta fl;
     * fl.second = sl;
    */

    // But
    union Kilo k;
    k.i = 42;
    union Romeo r;
    r.k = k;

    // Other
    int X = 42;
    double Y = 3.14;

    union xray u = (union xray){ .a = X };
    u = (union xray){ .b = Y }; 
}