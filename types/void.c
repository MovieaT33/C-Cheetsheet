void greet(void) {
    return;                         // Returns void.
    return void;                    // Error
}

int main(void) {
    greet();
    void x;                         // Error

    return 0;
}