/*
while (condition) {
    // code block to execute while condition is true
}

while (1) {
    // infinite loop
}
*/

#include <stdio.h>

// while (1); // Error

int main(void) {
    int count = 0;

    while (count < 5) {
        count++; // increment counter
        continue;
    }

    while (1) { };
    while (2);

    int a = 10;
    while (--a);

    while (1)
    {
        while (1)
        {
            break;
        }
        break;
    }

    while (a++)

    return a;
}