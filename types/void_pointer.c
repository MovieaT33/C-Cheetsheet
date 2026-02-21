int main() {
    int alpha = 10;
    void *ptr = &alpha;
    // *ptr = 20; // Error: cannot dereference void pointer

    *(int*)ptr = 20;

    // GCC extensions:
    ptr += 1;
    ptr -= 2;
}