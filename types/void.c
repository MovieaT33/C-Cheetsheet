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
    return; // returns void
    // return void; // error: expected expression before 'void'
}

int main(void)
{
    foo();
    // void var; // error: variable declared void
}