void foo(void)
{
    return;

    // Function dead code
    int foo = 1;
    foo++;
    // return foo; // error: 'return' with a value, in function returning void
}

int main(void)
{
    // Overwritten variable
    int x = 10;
    x = 20;

    // Dead code examples
    int y = 10;

    if (0) y++;
    for (; 0; ) y--;
    for (; 1; ) {
        break;
        continue;
        y *= 5;
    }
    while (0) y += 2;
    while (1) {
        break;
        y = y ^ 0x11;
    }

    switch (0)
    {
        case 0: break;
        case 1: break; // dead case
    }

    switch (2)
    {
        case 2: break; y = 5;
    }

    goto loop;
    y /= 2;
loop:

    return y; // 10
}