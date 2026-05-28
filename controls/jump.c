#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void second(void)
{
    printf("Second\n");
    longjmp(buf, 10);
}

void first(void)
{
    printf("First\n");
    second();
}

int main(void)
{
    /*
    Start
    First
    Second
    End: 10
    */

    int code = setjmp(buf);
    if (code == 0) {
        printf("Start\n");
        first();
    } else if (code == 5) {
        printf("Code: 5");
    } else {
        printf("End: %d\n", code);
    }
}