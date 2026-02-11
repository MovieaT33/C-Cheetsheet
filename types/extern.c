#include <stdio.h>

extern a = 10;  // Error
int varFromThisFile = 42;

{ ; } // Error

int func() {
    int varFromThisFile = 3840;
    {
        extern int varFromThisFile;
        return varFromThisFile;
    }
}

varFromThisFile; // 42

int some_func(void) {
    extern char sharedVarFromAnotherFile;
    extern unsigned int func_2(int);
    extern int var1, var2; // var1 and var2 are integers.

    int x = 10;
    {
      extern x; // Error
      extern const int x; // Error
    }

    return func(); // 42
}

void increment() {
    extern int counter;
    counter++;
}
 
int counter = 0;
 
int main() {
    increment();
    printf("Counter: %d\n", counter);

    int X = 10;
    {
        int X = 20;
        extern int X; // Error
    }

    return 0;
}
