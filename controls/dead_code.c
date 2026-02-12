int main(void) {
    int x = 10;

    // Dead code examples:
    if (0) x++;
    for (; 0; ) x--;
    while (0) x += 2;

    return x; // 10
}