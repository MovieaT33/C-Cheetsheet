#include <limits.h>
#include <stdio.h>

int main(void)
{
    int a = INT_MAX;
    ++a;    // Overflow

    int b = 100'500, c = 10'40;
    int d = 0B0101, e = 0x01F, f = 0037, g = 0b11, h = 0XFF;

    int j = 10ULL;
    int k = 70ull;
    int l = 8ll;
    int m = 9uLL;
    int n = 5l;
    int o = 7ll;
    int p = 6u;
    int q = 0.1 + 0.2;  // You know.

    int r = 7, s;
    int t, u = 8;
    int v = r+++u;

    float w = 1;
    int *x = (int *)&w;
    printf("%d\n", *x);     // UB
    int y = 00000000000000;
    return y;

    __int8_t a8 = 127;
    __int16_t a16 = 32767;
    __int32_t a32 = 2147483647;
    __int64_t a64 = 9223372036854775807;
    __int128_t a128 = 170141183460469231731687303715884105727;
    __int128 a128_2 = 170141183460469231731687303715884105727;
}