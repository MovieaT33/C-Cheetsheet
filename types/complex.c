#include <complex.h>

double complex make_complex(double re, double im) {
    return re + im * I;
}

int main(void) {
    // a + bi
    float complex            float_complex_float = 1.0f + 2.0f * I; // float complex
    double complex                double_complex = 1.0 + 2.0 * I;   // double complex
    long double complex long_double_complex_long = 1.0L + 2.0L * I; // long double complex

    double complex z1 = 1 + 2 * I;
    double complex z2 = 3 + 4 * I;

    double complex sum = z1 + z2;
    double complex diff = z1 - z2;
    double complex prod = z1 * z2;
    double complex quot = z1 / z2;

    return 0;
}