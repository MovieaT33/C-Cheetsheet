void foo(void) {
    // return;      // Returns `void`
    // return void; // Error
}

int main(void) {
    foo();
    // void x; // Error
}