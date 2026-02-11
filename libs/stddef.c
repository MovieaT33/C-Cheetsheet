#include <wchar.h>
#include <stddef.h>
#include <stdio.h>

struct Point {
    int x;
    double y;
    wchar_t label;
};

int main(void) {
    // 1. NULL:
    int *ptr = NULL;
    if (!ptr) return 1;

    // 2. size_t:
    size_t n = 5;
    int arr[5] = {10, 20, 30, 40, 50};

    // 3. ptrdiff_t:
    ptrdiff_t diff = &arr[4] - &arr[1];

    // 4. offsetof:
    printf("%zu bytes\n", offsetof(struct Point, x));
    printf("%zu bytes\n", offsetof(struct Point, y));
    printf("%zu bytes\n", offsetof(struct Point, label));

    // 5. wchar_t:
    wchar_t wch = L'Ω';

    wchar_t name[] = L"Hello";
    size_t len = wcslen(name);

    return 0;
}