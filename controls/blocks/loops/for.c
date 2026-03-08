/*
for (initialization; condition; update) {
    // code block
}

for(;;) {
    // code executes forever
}

for (;;...); // Error
*/

// for (; 1; ) { } // Error

int main(void) {
    for (; 1; ) { }

    for (int i = 0; i < 5; i++) {
        // loop body executes 5 times: i = 0, 1, 2, 3, 4
    }

    // Iterating over an array:
    int arr[3] = {10, 20, 30};
    for(int i = 0; i < 3; i++) {
        arr[i] += 1; // increment each element by 1
    }

    int i = 0;
    for(; i < 5; )
        i++;

    for(int i = 0, j = 10; i < j; i++, j--) { // comma operator
        // multiple counters
    }

    for(int i = 0; i < 3; arr[i++] += 1); // all in header

    for(;;);
    for(;;)

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            break;
        }
        break;
    }
}