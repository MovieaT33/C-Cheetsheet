#include <stdarg.h>
#include <stdio.h>

int sum(const int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (register int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main(void) {
    int s = sum(4, 10, 20, 30, 40);
    printf("Sum: %d\n", s);

    return 0;
}