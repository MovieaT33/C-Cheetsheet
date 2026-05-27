#include <stdbool.h>

// #define bool _Bool // C99
// #define true 1
// #define false 0

int main(void)
{
    // sizeof(bool) = 1
    bool boolean_false = false;
    bool boolean_true  = true;

    bool a = 45;
    !!a == true; // evaluates to true (non-zero)
    bool b = 0;
    !!b == false; // evaluates to false (zero)

    return false;
}