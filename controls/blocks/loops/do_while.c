/*
do {
    // code block to execute
} while (condition);
*/

// do { } while (1); // Error

int main(void) {
    int count = 5;

    do { } while (1);
    do ; while (0);

    do {
        count++; // executes at least once
    } while (count < 5);

    return count;
}