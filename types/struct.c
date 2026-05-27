#include <stdlib.h>
#include <stddef.h>

struct {}; // warning: unnamed struct that defines no instances

struct EmptyStruct {};

// struct EmptyStruct {}; // error: redefinition of struct

struct Point1 {
    int x;
    _Alignas(16) int y;
};

typedef struct Point2 {
    int x;
    int y;
} Point2, point_2;

static point_2* get_point2(int x, int y)
{
    static point_2 p; // static to avoid returning address of local variable (stack storage)
    p.x = x;
    p.y = y;
    return &p;
}

typedef struct {
    int x, y;
} Point3, point_3;

struct Rectangle {
    struct Point1 top_left;
    struct Point1 bottom_right;
} __attribute__(packed);
// sizeof(Rectangle) = sizeof(Point1) * 2 = 16 B (no padding due to packed attribute)

struct BitField {
    unsigned int   a : ' '; // 4 B
    unsigned short b : 16;  // 2 B
    unsigned char  c : 2;   // 1 B
    // unsigned short d : 17; // error: width exceeds its type
};
// sizeof(BitField) = 8 B (due to alignment and padding)

struct Struct8 {
    int tag;
    union { // anonymous union
        int i;
        float f;
        char c;
    };
};

struct Struct9 {
    char c; // 1 B
    int  i; // 4 B
    char d; // 1 B
};
// sizeof(Struct9) != (sizeof(char) + sizeof(int) + sizeof(char)) due to padding
// sizeof(Struct9) = 12

struct Struct10 {
    int  i; // 4 B
    char c; // 1 B
    char d; // 1 B
};
// sizeof(Struct10) = 8

// See more: hot and cold fields

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
    char data[];            // flexible array member. Must be last member
    /* Or:
    char data[0];
    char data[1];
    char data[2];
    ...
    */
};

// 2 flexible arrays are not allowed
// struct bad {
//     char data[];
//     char data_2[];
// };

struct Foo { int a, b, c; } make_foo(void)
{
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

struct OldGCCStandard{
    int arr[0];
};

struct feature { int a[4]; };

struct point { int x, y, z; };

typedef struct Vec3 { int value[3]; } Vec3;

Vec3 zero_vec3()
{
    Vec3 v = {}; // all members initialized to 0
    return v;
}

struct {
    struct {
        // nothing
    };
};

int main(void)
{
    struct {}; // warning: unnamed struct that defines no instances

    // Declaring and initializing struct variables
    struct Point1 p1;
    p1.x = 10;
    p1.y = 20;
    struct Point1 p1_copy = p1;
    struct Point1 p2 = { .x = 10, 20 };
    struct Point1 p3 = (struct Point1){ .y = 20, .x = 10 };
    struct Point1 p4 = {10};
    struct Point1 p4_copy = p4;

    // Anonymous structs
    // struct {
    //     int is_ok;
    //     int code;
    // } Result = {1, 0};
    // struct {
    //     int is_ok;
    //     int code;
    // } Result_copy = Result; // error: invalid initializer

    struct {
        int x, y;
    } AnonPoint2 = { .x = 5, .y = 15 };

    struct {
        int x;
        int y;
    } AnonPoint3;
    AnonPoint3.x = 25;
    AnonPoint3.y = 35;

    struct AnonPoint4 {
        int how_to_name_this_var;
    } AnonPoint4 = {1};

    struct Struct8 e;
    e.tag = 1;
    e.i = 42;
    e.f = 3.14f; // overwrites e.i

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

    size_t off = offsetof(struct Struct9, d);

    struct S *zero = malloc(sizeof(OldGCCStandard) + sizeof(int) * 3);
    zero->arr[0] = 1;
    zero->arr[1] = 2;
    zero->arr[2] = 3;

    struct feature f(); // Must be realized

    int bar(int index) {
        return f().a[index];
    }

    struct point pt_array[10] = {
        [2].y = yv2,
        [2].x = xv2,
        [0].x = xv0
    };

    // Struct in function
    struct InFunc { int a; };

    return 0;
}

void in_func(void)
{
    struct InFunc f;
}