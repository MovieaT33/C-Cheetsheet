#include <assert.h>

#define PI 3.14159
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))

#define NOOP() do { ; } while(0)

#define __user   __attribute__((noderef, address_space(1)))

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define STR(x) #x
// STR(123) // -> "123"

#define CONCAT(a,b) a##b
// int var1 = 5;
// CONCAT(var,1) = 10;

# define malloc my_malloc

#define BEGIN {
#define END }

#define STR_2 "This is a very long \
string"

#define LIB <stdio.h>
#include LIB

_Static_assert(SQUARE(5) == 25, "error");
static_assert(sizeof(int) == 4, "error");

int main(void) BEGIN
    double area = PI * 5 * 5;
    int max_value = MAX(10, 20);
    #undef PI MAX

    if (likely(1)) BEGIN END
    if (unlikely(0)) BEGIN END
END