#define PI 3.14159
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define STR(x) #x
// STR(123) // -> "123"

#define CONCAT(a,b) a##b
// int var1 = 5;
// CONCAT(var,1) = 10;

# define malloc my_malloc

#define BEGIN {
#define END }

_Static_assert(SQUARE(5) == 25, "error");

int main(void) BEGIN
    double area = PI * 5 * 5;
    int max_value = MAX(10, 20);
    #undef PI MAX

    if (likely(1)) BEGIN END
    if (unlikely(0)) BEGIN END
END