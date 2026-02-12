int main(void) {
    signed char signed_char;
    signed int signed_integer = 0U;
    signed short signed_short_integer;
    signed long signed_long_integer = 0UL;
    signed long long signed_long_long_integer = 0ULL;
    signed __int128 signed_128_bit_integer; // GCC extension

    // Or:
    char a;
    int b;
    short c;
    long d;
    long long e;

    /* The same:
    signed char int signed_char;
    signed short int signed_short_integer;
    signed long int signed_long_integer = 0UL;
    signed long long int signed_long_long_integer = 0ULL;
    */

    /* You can move qualifiers around:
    const int signed volatile register var;
    volatile static int signed const *p;
    */

    return 0;
}