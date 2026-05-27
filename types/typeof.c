// `__typeof__` / `typeof` is a GCC extension that allows you to obtain the type of an expression

#define MAX(a, b) ({        \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a > _b ? _a : _b;      \
})

void foo(int, float);

int main(void)
{
    // `p1` and `p2` are pointers to the function `foo`
    __typeof__(foo) *p1 = foo;
    __typeof__(foo) *p2 = &foo;

    int a = 5;
    __typeof__(&a) p3 = &a; // `p` has int* type
    __typeof__(a) b = 10;

    const int c = 'ABCD'; // warning: multi-character character constant
    __typeof__(c) d = 10;

    int i = 0;
    __typeof__(i++) j;
    // i = 0

    double e();
    __typeof__(e()) f; // `f` is double

    struct Struct { int var; };
    struct Struct s1;
    __typeof__(s1) s2;
    __typeof__(s1.var) g;

    const volatile int h;
    typeof(h) k;
    __typeof_unqual__(h) l;
}