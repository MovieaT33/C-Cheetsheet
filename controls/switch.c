#include <stdio.h>

// switch (1) {} // Error

int main(void) {
    switch (0) { }
    switch (1) ;

    int expression = 1;

    switch(expression) {
        case 0:
            // Code executed if `expression == 0`
            break;
        case 1:
            // Code executed if `expression == 1`
            break;
        default:
            // Code executed if no case matches
    }

    // Fall-through
    int x = 15;
    switch (x) {
        case 15:
            puts("1");
            __attribute__((fallthrough));
        // case 15: // duplicate case value error
        case 20:
            puts("2");
            break;
    }

    // Output: `1\n2\n`

    // See: https://en.wikipedia.org/wiki/Duff's_device
    // Switch + do / while
    switch (x) {
        case 15:
            do {
                --x;
        case 14:
            x -= 13; continue;
        case 0:
                break;
            } while (x != 0);
    }

    // Switch + if, goto, for and while
    int y = 11;
    int ten = 10;
    switch (x) {
        case 15:
            if (y > 10) {
                x -= 5;
                goto label;
        case_10:
        case ten:
            for (int i = 0; i < 5; ++i) {
                x += i;
            case 35:
                goto end;
            }
        label:
            while (x < 20) {
                x++;
            }
            goto case_10;
            }
        end: while (1) {
            goto default_case;
        }
        default_case:
        default:
            break;
    }

    // Switch + block
    switch (x) {
        case 15: {
            int z = x * 2;
            printf("%d\n", z);
            break;
        case 30: {
            int z = x / 2;
            printf("%d\n", z);
            break;
        } }
        default:
            break;
    }

    switch (x) {
        default:
            break;
        case 15:
            break;
    }

    // Special:
    switch (1);

    switch (1) case 10 + 5:

    // switch () {} // Error

    switch (x) {
        case 0 ... 10: // GCC extension
            break;
    }

    // switch (x) { case x: } // Error
}