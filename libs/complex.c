#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    // 1. double complex (typedef from complex.h):
    double complex z1 = 1.0 + 2.0 * I;

    // 2. double _Complex
    double _Complex z2 = 3.0 + 4.0 * I;

    // 3. double _Imaginary
    double _Imaginary y = 5.0 * I;

    printf("=== double complex z1 ===\n");
    printf("z1 = %.2f + %.2fi\n", creal(z1), cimag(z1));
    printf("|z1| = %.2f\n", cabs(z1));
    printf("arg(z1) = %.2f rad\n", carg(z1));
    printf("conj(z1) = %.2f + %.2fi\n", creal(conj(z1)), cimag(conj(z1)));
    printf("sqrt(z1) = %.2f + %.2fi\n", creal(csqrt(z1)), cimag(csqrt(z1)));

    printf("\n=== double _Complex z2 ===\n");
    printf("z2 = %.2f + %.2fi\n", creal(z2), cimag(z2));
    printf("|z2| = %.2f\n", cabs(z2));
    printf("arg(z2) = %.2f rad\n", carg(z2));
    printf("conj(z2) = %.2f + %.2fi\n", creal(conj(z2)), cimag(conj(z2)));
    printf("sqrt(z2) = %.2f + %.2fi\n", creal(csqrt(z2)), cimag(csqrt(z2)));

    printf("\n=== double _Imaginary y ===\n");
    printf("y = %.2fi\n", cimag(y));
    printf("|y| = %.2f\n", cabs(y));
    printf("arg(y) = %.2f rad\n", carg(y));
    printf("conj(y) = %.2fi\n", cimag(conj(y)));
    printf("sqrt(y) = %.2f + %.2fi\n", creal(csqrt(y)), cimag(csqrt(y)));

    return 0;
}