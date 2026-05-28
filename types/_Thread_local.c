#include <stdio.h>
#include <threads.h>

_Thread_local int counter = 0;

int worker(void *arg)
{
    counter++;
    printf("counter = %d\n", counter);
    return 0;
}