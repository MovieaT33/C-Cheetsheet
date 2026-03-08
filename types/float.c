#include <math.h>

int main(void) {
    /*
     * `f` means `float`, `l` means `long double`. If there is no suffix, it is a `double` by default.
     */

    float float_integer             = 3.14f;
    double double_integer           = 3.141592653589793;
    long double long_double_integer = 3.141592653589793238L;
    float i_use_nixos_btw           = 1.;

    // Positive infinity (macro):
    float f_pos_inf = INFINITY;
    double d_pos_inf = 1.0 / 0.0;   // alternative
    long double ld_pos_inf = 1.0l / 0.0L;

    // Negative infinity (macro):
    float f_neg_inf = -INFINITY;
    double d_neg_inf = -1.0 / 0.0;
    long double ld_neg_inf = -1.0L / 0.0L;

    // NaN (Not a Number, macro):
    float f_nan = NAN;
    double d_nan = 0.0F / 0.0;
    long double ld_nan = 0.0L / 0.0L;

    // Hexadecimal floating-point literals (C99):
    float new_feature = 0x1.921fb54442d18p+1f;
    double new_feature_double = 0x1.921fb54442d18p+1;
    long double new_feature_long_double = 0x1.921fb54442d18p+1L;

    // Guaranteed sizes:
    _Float16 x;
    _Float32 y;
    _Float64 z;
    _Float128 w;

    return 0;
}
