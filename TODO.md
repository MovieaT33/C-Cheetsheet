# 1
void (*foo)() = (void (*)())bar;, void *a = (void *)b;

# 2
__attribute__((address_space(1)/format(...)))

# 3
__STDC_*

# 4
union {int a[];};, struct {void a();}

# 5
#embed unsequencible reproducible

# 6
__builtin_stdc_*

# 7
void f(int n, int (*a)[n]);

# 8
void f(int g(double)); // -> void f(int (*g)(double));

# 9
void f(int a[10]) {
    sizeof(a); // sizeof(int*) -> sizeof(pointer) -> 4 bytes (64-bit)
}

# 10
printf("%zu\n", _Alignof(double)); // operator

# 11
a + b; // -> (int)a + (int)b;

# 12
const int x = 5;
int *p = (int*)&x;
*p = 10; // UB

printf("%d\n", x); // 5
*p = 10;
printf("%d\n", x); // 5

# 13
int arr[3];
printf("%p\n", (void*)(arr + 1));  // + sizeof(int)
printf("%p\n", (void*)(&arr + 1)); // + sizeof(arr)

# 14
int (*p)[4] = arr;

# 15
for (int i = 0; i < 3; i++) {
label:
    printf("%d\n", i);
}
goto label;

# 16
int n = 3;
int (*p)[n];

# 17
struct S { int a[1]; };
struct S *s = malloc(sizeof(struct S) + sizeof(int) * 10);

# 18
void (*f_ptr)() = ();