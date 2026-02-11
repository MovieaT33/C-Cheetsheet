#include <stdio.h>
#include <cmoball.h>

#define NoA(...) CMOBALL(FOO, __VA_ARGS__)
#define FOO_3(x,y,z) "Three"
#define FOO_2(x,y)   "Two"
#define FOO_1(x)     "One"
#define FOO_0()      "Zero"

int main(void)
{
    puts(NoA());
    puts(NoA(1));
    puts(NoA(1, 1));
    puts(NoA(1, 1, 1));

    return 0;
}