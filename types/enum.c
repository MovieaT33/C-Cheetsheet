#include <stdio.h>

enum A : short {    // C23
    DEBUG = 100,
    INFO = 'a',
    WARNING,
    ERROR,
    CRITICAL, // trailing comma
};

typedef enum permissions {
    READ    = 1 << 0,  // 1
    WRITE   = 1 << 1,  // 2
    EXECUTE = 1 << 2   // 4
} perms, *p_perms;


enum state {
    // Unrecommended style (multi-character literal), but valid in C.
    waiting = 'WAIT',
    running = 'RUN!',
    stopped = 'STOP',
};

enum {}; // Error

int main(void) {
    enum {}; // Error

    // Example 1
    int perms = READ | EXECUTE;
    if (perms & WRITE) { /* ... */ }    // false

    // Example 2
    enum Weekday { MON, TUE, WED, THU, FRI, SAT, SUN };

    // MON = 0, TUE = 1, WED = 2, THU = 3, FRI = 4, SAT = 5, SUN = 6
    enum Weekday today = WED;

    if (today == WED)
        printf("Today is Wednesday\n");

    // Example 3
    enum ErrorCode {
        SUCCESS = 0,
        ERROR_FILE = 1,
        ERROR_MEMORY = 'd',
    };

    enum ErrorCode some_error = ERROR_MEMORY;
    printf("Error code: %d\n", some_error); // Output: `100`

    // Example 4
    enum SomeEnum {
        VAL1 = 1,
        VAL2 = 2,
        VAL3 = 3
    } var = VAL2;

    // Example 5
    enum {
        ALPHA = 10,
        BETA,
        GAMMA = 20,
        DELTA
    } unnamed_var;
    printf("BETA: %d, DELTA: %d\n", BETA, DELTA);   // Output: `BETA: 11, DELTA: 21`

    return 0;
}