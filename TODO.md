#
void (*foo)() = (void (*)())bar;, void *a = (void *)b;

#
__attribute__((address_space(1)/format(...)))

#
__STDC_*

#
__m512

#
union {int a[];};, struct {void a();}

#
if (int y = x + 2);

#
sizeof(a += 2);

#
#embed unsequencible reproducible

#
__builtin_stdc_*

#
static_assert

#
typedef struct { int a[3]; } Arr;

Arr f(void) {
    return (Arr){{1, 2, 3}};
}

#
`int *a[10]` VS `int (*a)[10]`

#
enum E { A = 1ULL << 40 };

#
typedef int T;

void f(void) {
    int T = 5;
}

#
struct A { int x; };
typedef int A;

struct A a1; // struct
A a2;        // int

#
struct Outer {
    struct { int x, y; };
};

#
void f(int n, int (*a)[n]);

#
char s[3] = "abc"; // without null-terminator

#
void f(int g(double)); // -> void f(int (*g)(double));

#
void f(int a[10]) {
    sizeof(a); // sizeof(int*) -> sizeof(pointer) -> 4 bytes (64-bit)
}

#
*p++;
(*p)++;

#
switch(without;)

#
switch(x) {
    default:
        printf("def\n");
        break;
    case 1:
        printf("one\n");
}

#
int n = 5;
sizeof(int[++n]); // `n` = 6;

#
printf("%zu\n", _Alignof(double)); // operator

#
int x = (5 && 2); // x = 1 int not bool

#
if (-1 < 1U)

#
f(i++, i++); // UB

#
int main() {
    return; // 0
}

//
int a[3], b[3];
a = b;

#
struct S { int a[3]; };
struct S s1, s2;
s1 = s2; // OK

#
char *a = "hi";
char *b = "hi";
// `a == b` can be true

#
sizeof("abc") // 4

#
a + b; // -> (int)a + (int)b;

#
const int x = 5;
int *p = (int*)&x;
*p = 10; // UB

printf("%d\n", x); // 5
*p = 10;
printf("%d\n", x); // 5

#
float f = 1.0;
int *p = (int*)&f;
printf("%d\n", *p); // UB

#
unsigned char *p = (unsigned char*)&x; // magic type

#
int a[3];
int *p = a + 3; // ОК (one past the end rule)
*p = 5;         // UB

#
int arr[3];
printf("%p\n", (void*)(arr + 1));  // + sizeof(int)
printf("%p\n", (void*)(&arr + 1)); // + sizeof(arr)

#
int (*p)[4] = arr;

#
int *p = NULL;
sizeof *p;

#
int *p = &(int){42};

#
int *p;
{
    p = &(int){5};
}

#
int *p = NULL;
p++; // UB

#
void *p;
p++;

#
1 << -1; // UB

#
int x = -1;
x >> 1; // Arithmetic or Logic?

#
#define NOOP() do { ; } while(0)

#
int a[0] = {};

#
for (int i = 0; i < 3; i++) {
label:
    printf("%d\n", i);
}
goto label;

#
int n = 3;
int (*p)[n];

#
int n = 10;
int a[n];
sizeof(a);     // 3 * sizeof(int)
sizeof(a + 0); // sizeof(int*)

#
int a;
int *p = (int*)((char*)&a + 1);

#
struct S { int a[1]; };
struct S *s = malloc(sizeof(struct S) + sizeof(int) * 10);

#
void (*f_ptr)() = ();
