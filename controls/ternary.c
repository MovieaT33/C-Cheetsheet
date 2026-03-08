/* Syntax:
condition ? expression_if_true : expression_if_false;
condition ?: expression_if_false; // GCC extension, not standard C
*/

#include <stdio.h>

#define NUM 50

int bool = NUM ? 1 : 0;             // bool = 1
// int bool_2 = bool ? 1 : 0;       // Error
constexpr int bool_3 = NUM ? 1 : 0;
int bool_4 = bool_3 ? 1 : 0;        // bool_4 = 1

int some_func(void) {
    return 1;
}

int main(void) {
    int a = 10, b = 20;
    int res = a > b ? a, some_func() : b;

    int or_like_this = a ?: b; // GCC extension

    return res; // 20
}