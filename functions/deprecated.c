#include <stdlib.h>

void __attribute__((deprecated)) func(void) { }

// Or:

[[deprecated]]
[[noreturn]] // can be combined with other attributes
void func2(void) { exit(1); }
