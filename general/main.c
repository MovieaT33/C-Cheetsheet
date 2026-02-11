#include <stdio.h>
#include <stdlib.h>

void my_init(void) __attribute__((constructor));   // This function will be called before main() is executed.
void my_cleanup(void) __attribute__((destructor)); // This function will be called after main() has finished executing, even if main() exits with an error.

void my_init(void) {
    printf("my_init()\n");
}

void my_cleanup(void) {
    printf("my_cleanup()\n");
}

_Noreturn void some_error(void) {
    exit(1);
}

// Entry point. As default returns 0 (`int`).
int main(int argc, char **argv) { // Or `<any_type_or_empty> main(...)`, but it is unrecommended. And `char *argv[]` is equivalent to `char **argv`.
    int code = 0; // Default return code
    code = 1;     // Error occurred

    some_error();
    exit(code);
    abort();

    printf("main()\n");

    return code; // Equal to `exit(code);`. \
    Can be omitted, then it will return 0 by default. \
    But it is better to be explicit. \
    Note that `return` and `exit()` are not the same. \
    `return` will exit the current function, while `exit()` will terminate the entire program immediately.
}