typedef int v4si __attribute__ ((vector_size (16)));

int main(void) {
    v4si a = {1, 2, 3, 4};
    v4si b = {5, 6, 7, 8};

    // Vector addition:
    v4si c = a + b; // c = {6, 8, 10, 12}

    // Vector multiplication:
    v4si d = a * b; // d = {5, 12, 21, 32}

    // Accessing elements:
    int x = c[0]; // x = 6
    int y = d[2]; // y = 21

    return x + y; // returns 27
}