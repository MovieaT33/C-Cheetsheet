int main() {
    // Valid usage of void pointer.
    void *ptr;
    int a = 10;
    ptr = &a;
    // *ptr = 20;       // Error: cannot dereference void pointer.

    *(int*)ptr = 20;   // Valid: cast to appropriate type before dereferencing.

    ptr += 1;       // GCC extension
    (int*)ptr *= 2; // Valid
}