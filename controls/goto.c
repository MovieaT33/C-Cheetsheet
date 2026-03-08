// goto <label>; // Error

int goto_is_frequently_used_in_linux = 1;

#include <stdio.h>

// main:
int main(void) {
    int i = 0;

    // Simple loop with goto:
start_loop:
    if (i >= 5) goto end_loop;

    i++; // increment
    goto start_loop; // jump back to start of loop

end_loop:
    // `i == 5` after loop
    i++; // continue execution after the loop

    // Nested loops example using goto:
    int j, k;
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
            if(j == 1 && k == 1) goto exit_loops;
        }
    }

exit_loops:
    // execution resumes here after breaking out of nested loops

    // Computed goto:
    void *link = &&c_goto; // GCC extension
    goto *link;
    c_goto:

    int *table[] = {&&l0, &&l1, &&l2};

    goto *table[1];

    l0:
    l1:
    return 1;
    l2:

    goto what;
    int x = 5;
    what:
    printf("%d", x); // garbage

    // Infinity loop
    for (int i = 0; i < 3; i++) {
label:
        printf("%d\n", i);
    }
    goto label;

    return 0;
}