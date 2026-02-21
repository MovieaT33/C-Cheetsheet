// continue; // Error

int main(void) {
    // continue; // Error

    // `while` loop:
    int count = 0;
    while (count < 10) {
        count++;
        if (count == 5) continue; // skip rest of this iteration when `count == 5`
        // any code here is skipped when `count == 5`
    }

    // `for` loop:
    for (int i = 0; i < 10; i++) {
        if (i == 7) continue; // skip iteration when `i == 7`
        // code here will not execute when `i == 7`
    }

    // `do...while` loop:
    int j = 0;
    do {
        j++;
        if (j == 3) continue; // skip rest of loop body when `j == 3`
        // code here is skipped for `j == 3`
    } while (j < 10);
}