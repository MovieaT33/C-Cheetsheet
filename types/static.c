// Static storage is data or bss (uninitialized variables).

#include <stdio.h>

void counter() {
    static int count = 0;   // initialized only once
    count++;
    printf("Count = %d\n", count);
}

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

static Date today(void) {
    static Date currentDate = {
        .year = 2025,
        .month = 12,
        .day = 25,
    };
    return currentDate;
}

void sum(int a[restrict static 1024],
         int b[const restrict static 1024]) {
    /* `a` and `b` is not NULL
        and have at least 1024 elements. */
    for (int i = 0; i < 1024; ++i)
        a[i] += b[i];
}

int main(void) {
    // Example 1:
    counter(); // Output: `Count = 1`
    counter(); // Output: `Count = 2`
    counter(); // Output: `Count = 3`

    // Example 2:
    static int secret = 42; // visible only in this file

    // Example 3:
    helper();

    // Example 4:
    Date d = today();

    // Example 5:
    int x[512], y[512];
    sum(x, y);  // UB

    // Example 6:
    // int arr1[static 1024];   // Error
}

static void helper() {} // accessible only in this file