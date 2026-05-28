#include <stdio.h>

// switch (1) {} // error: expected identifier or '(' before 'switch'

int main(void)
{
    // switch () {} // error: expected expression before ')' token

    switch (0);
    switch (1) { }
    // switch (15) { case 10 + 5: case 15: } // error: duplicate case value
    // switch (var) { case var: }            // error: case label does not reduce to an integer constant

    int expression = 1;
    switch (expression) {
        case 0:
            // Code executed if `expression == 0`
            break;
        case 1:
            // Code executed if `expression == 1`
            break;
        default:
            // Code executed if no case matches
    }

    char x = 15;

    switch (x)
    {
        // printf("Hello, World!\n"); // warning: statement will never be executed
        while (1) {
            case 0:
                case 1:
                    break;
        }
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
        case 15:
    }

    switch (x) {
        case 0 ... 10: // GCC extension
            break;
        case 'A' ... 'Z':
            break;
    }

    // Fall-through: 1 2
    switch (x) {
        case 15:
            puts("1");
            __attribute__((fallthrough)); // optional
        // case 15: // error: duplicate case value
        case 20:
            puts("2");
            break;
    }

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

    int foo = 100;
    switch (foo) {
        int bar = 20;
        case 100:
            c = foo + bar;
            printf("%d %d %d\n", foo, bar, c); // 100 0 100
    }

    // Switch + if, goto, for and while
    short y = 11, ten = 10;
    switch (x) {
        case 15:
            if (y > 10) {
                x -= 5;
                goto label;
        case_10:
        case 10:
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
}