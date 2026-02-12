int main(void) {
    auto int a = 5; // Storage-class (stack) specifier. Only historical. No sense.

    /* Errors:
    static auto var;
    register auto var;
    */

    return a;
}