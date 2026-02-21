// Errors (not in function):
/*
 * if (1) { }
 * while (1) { }
 * for (; 1; ) { }
 */

int main(void) {
    int x = 5;

    // `if`:
    if (x > 0)
        printf("x is positive\n");
    else if (x < 0)
        printf("x is negative\n");
    else
        printf("x is 0\n");

    printf("This always prints\n");

    // `for`:
    for (int i = 0; i < 10;) ++i;
    for (int j = 0; j < 10;)
        ++j;

    // `while`
    int k = 0;
    while (k < 10) ++k;
    while (k < 5)
        --k;

    // `do / while`:
    do printf("Hello\n"); while (0); // Semicolon is required here.

    return k;
}