/* `__typeof__` is a GCC extension
   that allows you to obtain the type of an expression. */

#define MAX(a, b) ({            \
    __typeof__(a) _a = (a);     \
    __typeof__(b) _b = (b);     \
    _a > _b ? _a : _b;          \
})

void foo(int, float);

int main(void) {
    int a = 5;
    __typeof__(a) b = 10;

    const int c = 5;
    __typeof__(c) x = 10;

    int i = 0;
    __typeof__(i++) j;  // `i` is NOT incremented

    double c();
    __typeof__(c()) d;  // `d` is double.

    __typeof__(&a) p = &a;  // `p` is int*.

    struct S { int e; };
    struct S s;

    __typeof__(s) s2;
    __typeof__(s.e) f;

    __typeof__(foo) *fp = foo;  // `fp` is pointer to function.
    __typeof__(foo) *bp = &foo;

    return 0;
}