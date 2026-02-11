#include <stdio.h>

#define print_type(v) \
    printf("%s\n", \
        _Generic((v), \
            int: "int", \
            float: "float", \
            double: "double", \
            default: "unkown"))

int main(void) {
    int a = 5;
    print_type(a);
}