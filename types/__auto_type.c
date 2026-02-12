#include <stdint.h>

typedef int32_t i32;

i32 main(void) {
    // GCC extension: `__auto_type`
    __auto_type x = 42;
    __auto_type y = 3.14;
    __auto_type z = "Hello, World!";

    return x;
}