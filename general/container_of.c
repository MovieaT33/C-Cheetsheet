#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void func1(void) { printf("Func1\n"); }
void func2(void) { printf("Func2\n"); }

typedef struct Command {
    const char *name;
    void (*handler)(void);
} Command;

int main() {
    Command cmds[] = {
        {"one", func1},
        {"two", func2},
        {NULL, NULL} // null-terminated
    };

    Command *cmd = container_of(&cmds[0].handler, Command, handler);
    printf("%s\n", cmd->name); // "one"

    cmd->handler();

    return 0;
}