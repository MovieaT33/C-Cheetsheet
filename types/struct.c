#include <stdlib.h>
#include <stddef.h>

struct Empty {};

struct Point {
    int x;
    _Alignas(16) int y;
};

typedef struct SomePoint {
    int x;
    int y;
} SomePointType, some_point_type;

static some_point_type* get_point(int x, int y) {
    static some_point_type p;   // Static to avoid returning address of local variable (stack storage).
    p.x = x;
    p.y = y;
    return &p;
}

typedef struct {
    int x;
    int y;
} AnotherPointType, another_point_type;

struct Rectangle {
    struct Point top_left;
    struct Point bottom_right;
} __attribute__(packed);
// sizeof(Rectangle) = sizeof(Point) * 2 = 16 bytes (no padding due to packed attribute).

struct BitField {
    unsigned int   a : ' ';  // 4 bytes
    unsigned short b : 16;  // 2 bytes
    unsigned char  c : 2;   // 2 bits
};
// sizeof(BitField) = 8 bytes (due to alignment and padding).

struct Example {
    int tag;
    union {         // anonymous union
        int i;
        float f;
        char c;
    };
};

struct A {
    char c;     // 1 byte
    int  i;     // 4 bytes
    char d;     // 1 byte
};
// sizeof(A) != (sizeof(char) + sizeof(int) + sizeof(char)) due to padding.
// sizeof(A) = 12

struct BetterThanA {
    int  i;     // 4 bytes
    char c;     // 1 byte
    char d;     // 1 byte
};
// sizeof(BetterThanA) = 8.

// See more: hot and cold fields.

struct What {
    unsigned char;
    int;
    char;
    float;
};

struct foo {
    unsigned char x : 5;
    unsigned short  : 0;
    unsigned char;          // new word
};

struct bar {
    short len;
    char data[];            // Flexible array member. Must be last member.
};

// 2 flexible arrays are not allowed.
// struct bad {
//     char data[];
//     char data_2[];
// };

struct Foo { int a, b, c; } make_foo(void) {
    struct Foo ret = { .c = 3 };
    ret.a = 11 + ret.c;
    ret.b = ret.a * 3;
    return ret;
}

struct FirstLevel {
    struct SecondLevel {
        struct ThirdLevel {
            int value;
        } third;
    } second;
};

struct Person {
    const char *name;
    int age;
};

struct {}; // Error

struct OldGCCStandard{
    int arr[0];
};

struct feature { int a[4]; };

struct point { int x, y, z; };

int main(void) {
    struct {};

    // Declaring and initializing struct variables:
    struct Point p1;
    p1.x = 10;
    p1.y = 20;
    struct Point p1_copy = p1;

    struct Point p2 = { .x = 10, 20 };

    struct Point p3 = (struct Point){ .y = 20, .x = 10 };

    struct Point p4 = {10};
    // p4.y = 0;

    struct {
        int x;
        int y;
    } AnonymousPoint = { .x = 5, .y = 15 };

    struct {
        int x;
        int y;
    } AnotherAnonymousPoint;
    AnotherAnonymousPoint.x = 25;
    AnotherAnonymousPoint.y = 35;

    struct Example e;

    e.tag = 1;
    e.i = 42;
    e.f = 3.14f;    // overwrites e.i

    struct {
        int year, month, day;
        int hour, minute, second;
    } date_time = {
        .year = 2025, 12, 24,
        .hour = 13, 16, 0,
    };

    struct bar *b = malloc(sizeof(struct bar) + 100 * sizeof(char));
    b->len = 100;
    for (int i = 0; i < b->len; ++i)
        b->data[i] = (char)i;

    struct ThirdLevel tl = { .value = 42 };
    struct SecondLevel sl = { .third = tl };
    struct FirstLevel fl = { .second = sl };

    struct Person records[] = {
        "John",   20,
        "Bertha", 40,
        "Andrew", 30, // trailing comma
    };

    size_t off = offsetof(struct A, d);

    struct S *zero = malloc(sizeof(OldGCCStandard) + sizeof(int) * 3);
    zero->arr[0] = 1;
    zero->arr[1] = 2;
    zero->arr[2] = 3;

    //
    struct feature f(); // Must be realized.

    int bar(int index) {
        return f().a[index];
    }

    //
    struct point pt_array[10] = {
        [2].y = yv2,
        [2].x = xv2,
        [0].x = xv0
    };

    return 0;
}