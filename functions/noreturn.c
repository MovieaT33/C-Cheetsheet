#include <stdlib.h>
#include <stdio.h>

/* Attributes syntax:
[[attribute]]
*/

[[noreturn]]
void bye() {exit(0);}

_Noreturn void panic(void) { // C standard
    my_abort();
}

void __attribute__((noreturn)) my_abort(void) { // GCC extension
    printf("Aborting...\n");
}

noreturn void fail() {
    my_abort();
}