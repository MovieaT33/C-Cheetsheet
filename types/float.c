#include <math.h>

int main(void) {
    float float_integer             = 3.14f;
    double double_integer           = 3.141592653589793;
    long double long_double_integer = 3.141592653589793238L;

    // Positive infinity
    float f_pos_inf = INFINITY;
    double d_pos_inf = 1.0 / 0.0;   // alternative
    long double ld_pos_inf = 1.0L / 0.0L;

    // Negative infinity
    float f_neg_inf = -INFINITY;
    double d_neg_inf = -1.0 / 0.0;
    long double ld_neg_inf = -1.0L / 0.0L;

    // NaN
    float f_nan = NAN;
    double d_nan = 0.0 / 0.0;
    long double ld_nan = 0.0L / 0.0L;

    return 0;
}