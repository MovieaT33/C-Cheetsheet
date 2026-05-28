// `goto` is frequently used in the Linux kernel

// goto start_loop; // error: expected identifier or '(' before 'goto'

#include <stdio.h>

int* alloc(int init, int load, int run)
{
    if (init != 0)
        goto fail;

    if (load != 0)
        goto fail;

    if (run != 0)
        goto fail;

    return (int*)1;

    fail:
        return NULL;
}

int main(void)
{
    // goto unkown_loop; // error: label used but not defined

    // Simple loop with goto
start_loop:
    int i = 0;
    if (i >= 5) goto end_loop;

    i++; // increment
    goto start_loop; // jump back to start of loop

end_loop:
    // i = 5

    // Nested loops example using goto
    for (char j = 0; j < 3; j++) {
        for (char k = 0; k < 3; k++) {
            if (j == 1 && k == 1) goto exit_nested_loops;
        }
    }

exit_nested_loops:
    // Execution resumes here after breaking out of nested loops

    // Computed goto (GCC extension)
    void *link = &&computed_goto;
    goto *link;
    computed_goto:

    int *table[] = {&&l0, &&l1, &&l2};
    goto *table[1];

    l0: // 0 -> 2
    printf("0\n");
    goto l2;

    l1: // 1 -> 0 -> 2
    printf("1\n");
    goto l0;

    l2: // 2
    printf("2\n");

    // Skipped initialization
    goto skip;
    int x = 5;
    skip:
    printf("%d", x); // garbage

    // Infinity loop
    for (int i = 0; i < 3; i++) {
infinity_loop:
        printf("%d\n", i);
    }
    printf("End loop\n");
    goto infinity_loop;
}