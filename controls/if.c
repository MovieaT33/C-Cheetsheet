// if (5) {} // Error

int main(void) {
    // if (;) { } // Error

    int x = 15;

    if (x < 10) { // When `x < 10` != 0 (true)
        // `x` is less than 10
    } else if (++x, x < 20) {
        // `x` is between 10 and 19
    } else {
        // `x` is 20 or more
    }

    int y = 7;
    if (y == x) {
        x = y;
    } if (x == y) {
        return 8 + y;
    }

    if (x == 5) { } else { return 7; }
    if (x == 100) { }
    if (x - 50 == 95 && 1) { if (1) { return -10; } else { return 10; } } else if (x == 10) { }
    else if (x == 15) { } else { return 1'000; }

    if (50 + 100) {}

    if (1);

    return x;
}