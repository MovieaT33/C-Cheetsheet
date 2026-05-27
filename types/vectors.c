// GCC SIMD extensions
typedef char   v16qi __attribute__((vector_size (16))); // quarter integer
typedef short  v8hi  __attribute__((vector_size (16))); // half integer
typedef int    v4si  __attribute__((vector_size (16))); // single integer
typedef float  v4sf  __attribute__((vector_size (16))); // single float
typedef double v2df  __attribute__((vector_size (16))); // double float

int main(void)
{
    v4si a = {1, 2, 3, 4};
    v4si b = {5, 6, 7, 8};

    // Operators
    v4si add_v = a + b;
    v4si sub_v = a - b;
    v4si mul_v = a * b;
    v4si div_v = b / a;
    v4si neg_v = -a;

    v4si not_v = ~a;
    v4si and_v = a & b;
    v4si or_v  = a | b;
    v4si xor_v = a ^ b;

    v4si gt_v = a > b;
    v4si lt_v = a < b;
    v4si eq_v = a == b;

    // Accessing elements
    int x = add_v[0]; // 6
    int y = neg_v[2]; // -3

    // Functions
    v4si rev = __builtin_shuffle(a, (v4si){3, 2, 1, 0}); // {4, 3, 2, 1}
    v4si mix = __builtin_shuffle(a, b, (v4si){0, 5, 2, 7}); // {1, 6, 3, 8}
}