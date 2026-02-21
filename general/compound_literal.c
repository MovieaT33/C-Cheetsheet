#include <stdio.h>

int sum(int *nums, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += nums[i];
    }
    return total;
}

int main(void) {
    (int){5} = 1;
    printf("Sum: %d\n", sum((int[]){1, 2, 3, 4, 5}, 5));

    return 0;
}