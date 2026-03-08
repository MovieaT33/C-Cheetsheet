#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void second() {
    printf("2\n");
    longjump(buf, 10);
}

void first() {
    printf("1\n");
    second();
}

int main() {
    int value = setjmp(buf);
    if (value == 0) {
        printf("Start\n"); first();
    } else {
        printf("End: %d\n", value);
    }
}