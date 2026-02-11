// C23
constexpr int square(int x) {   // Error, because functions cannot be constexpr.
    return x * x;
}

int main(void) {
    constexpr int n = square(5);    // Valued at compilation.
    return n;
}