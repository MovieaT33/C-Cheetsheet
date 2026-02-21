#include <stdio.h>

#define HELLO "Hello"

int main() {
    char hello[] = HELLO
                   ", world!";
    // hello == &hello[0].
    // sizeof(hello) == (13 + 1).

    char hello_2[] = "Hello\
, world!";

    char *string = "Hello, world!"; // Read-only storage.
    char string_array[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    printf("%s\n", string);
    printf("H" "e" "l" "l" "o");
    printf("%d\n", ({int a = 5; a;})); // 5

    char without_null[5] = "Hello";
    printf("%s\n", without_null); // "Hello" + garbage

    // `.rodata` (read-only) section
    char *a = "hi";
    char *b = "hi";
    // `a == b` is true

    return 0;
}