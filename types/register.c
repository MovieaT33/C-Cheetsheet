int main(void) {
    /*
    `register` suggests to the compiler to store the variable in a CPU register for faster access.
    Modern compilers usually ignore `register` and perform optimization **automatically**.
    You can use register with automatic (local) variables of scalar types.
    */
    register int x = 0;
    // int *pX = &x;    // Error

    // static register int y = 0;   // Error

    int a = 0;
    register int *pA = &a;  // OK
}
