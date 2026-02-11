#include <stdio.h>

// Inline function:
inline int add(int a, int b) {
    return a + b;
}

__attribute__((always_inline))
inline int multiply(int a, int b) {
    return a * b;
}

/* Notes about inline in C:

1. Inline is a suggestion to the compiler to replace a function call
   with the function body directly. However, the compiler may ignore it.

2. When using inline in multi-file projects:
   - If the function is not 'static', its definition must appear in
     **exactly one translation unit** with external linkage (or use 'extern inline').
   - Otherwise, you may get multiple definition errors during linking.

3. Inline functions with 'static':
   - Each translation unit gets its own copy.
   - Safe for multi-file projects and avoids multiple definition problems.

4. Inline does not guarantee inlining:
   - Modern compilers often ignore 'inline' for optimization heuristics.
   - You can force inlining in GCC/Clang with __attribute__((always_inline))
     or in MSVC with __forceinline.

5. Inline can be combined with other attributes:
   - e.g., `static inline`, `inline __attribute__((noreturn))`.
*/

int main(void) {
    int sum = add(3, 4); // compiler may inline this call
    printf("sum = %d\n", sum);

    return sum;
}