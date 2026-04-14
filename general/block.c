void function_scope_example() {
    int x = 1;
}

// `x` is not accessible here

int main(void) {
    // Block scope:
    { }
    int a = 5;
    {
        int a = 10;
        a; // 10
    }
    a; // 5

    // Nested blocks:
    int b = 20;
    {
        a; // 5
        int c = 30;
        {
            a; // 5
            int d = 40;
            b; // 20
            c; // 30
            d; // 40
        }
        // `d` is not accessible here
        b; // 20
        c; // 30
    }

    // Using in for loop:
    for (int i = 0; i < 3; i++) {
        // `i` is accessible here
    }
    // `i` is not accessible here

    int x = ({
        int y;
        y = 4;
    });

    // return x * (x + y); // Error: `y` is not accessible here
    return x; // 4
}