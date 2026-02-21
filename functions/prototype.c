// Function protype (declaration):
int add(int x, int y);

// Or:

int add(int, int);
// int add(float, double); // Error

int main(void) {
    int a = 5;
    int b = 10;

    int result = add(a, b);

    return result; // 15
}

// Definition:
int add(int x, int y) { // `add { return x + y; }` is invalid.
    return x + y;
}