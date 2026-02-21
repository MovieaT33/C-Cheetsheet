void f(int x) {
    if (x > 0) {
        __label__ inner; // local label declaration

        inner:
        printf("x = %d\n", x);

        if (x > 5)
            goto inner;
    }
}