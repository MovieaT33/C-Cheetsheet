#include <stdio.h>

struct Enumerate : void { // error: invalid 'enum' underlying type
    field
};

struct Struct {
    // void field; // error: field declared void
};

struct Union {
    // void field; // error: field declared void
};

void foo(void)
{
    return;         // returns void
    // return void; // error: expected expression before 'void'
}

int main(void)
{
    foo();
    // void var_1;        // error: variable declared void
    // char var_2 = void; // error: expected expression before 'void'
    short var_3 = foo();  // error: void value not ignored as it ought to be
}