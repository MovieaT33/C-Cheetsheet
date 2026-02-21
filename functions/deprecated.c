#include <stdlib.h>

void __attribute__((deprecated)) func(void) { }

// Or:

[[deprecated("reason")]]
[[noreturn]] // can be combined with other attributes
void func2(void) { exit(1); }

[[fallthrough]]
[[nodiscard("reason")]]
[[maybe_unused]]
[[clang::no_sanitize]]
void func_2() {}