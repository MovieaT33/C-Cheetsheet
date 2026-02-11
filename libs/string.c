#include <stdio.h>
#include <string.h>

#define SIZE 10

int main() {
    char buffer[SIZE];
    memset(buffer, 0, SIZE);

    for (register int i = 0; i < SIZE; ++i)
        printf("%d ", buffer[i]);

    char src[5] = {'H','e','l','l','o'};
    char dest[5];

    memcpy(dest, src, sizeof src);

    for(int i = 0; i < 5; ++i)
        printf("%c", dest[i]);

    return 0;
}