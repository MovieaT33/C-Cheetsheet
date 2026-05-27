void func_dead_code(void)
{
    return;
    int foo = 1;
    foo++;
}

int main(void)
{
    int x = 10;

    // Dead code examples
    if (0) x++;
    for (; 0; ) x--;
    while (0) x += 2;

    return x; // 10
}