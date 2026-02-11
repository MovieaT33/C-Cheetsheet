// if (1) { }
// while (1) { }
// for (; 1; ) { }

int main(void) {
    int x = 5;

    if (x > 0)
        printf("x is positive\n");

    printf("This always prints\n");

    int count = 0;
    if (count < 10)
        return 0;


    for (int i = 0; i < 10;) ++i;
    for (int j = 0; j < 10;)
        ++j;

    int k = 0;
    while (k < 10) ++k;
    while (k < 5)
        --k;

    return k;
}