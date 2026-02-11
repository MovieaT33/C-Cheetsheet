#include <stdatomic.h>

int main(void) {
    // Atomic functions: __atomic_*
    _Atomic int a = 5;
    return a;
}