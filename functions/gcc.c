/* See all GCC functions attributes here:
https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Function-Attributes.html#Function-Attributes
*/

#include <stdlib.h>

void bar(void* ptr) {}

void foo(void)
{
    __attribute__((cleanup(bar)) char *buf = malloc(1'024);
}