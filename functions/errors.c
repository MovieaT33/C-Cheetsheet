void f1()
{
    // error: implicit declaration of function 'f2'
    // note: previous implicit declaration of 'f2' with type 'void()'
    f2();
}

void f2() // warning: conflicting types for 'f2'; have 'void()'
{
    return;
}

int f3() {
    f4(); // error: implicit declaration of function 'f4'
}

int f4() {
    return;
}