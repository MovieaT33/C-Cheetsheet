// Self-modifying code:
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

int main() {
    unsigned char code[] = {
        0xB8, 0x01, 0x00, 0x00, 0x00, // mov eax, 1
        0xC3                          // ret
    };

    void *mem = mmap(NULL, 4096,
                     PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_PRIVATE | MAP_ANONYMOUS,
                     -1, 0);

    memcpy(mem, code, sizeof code);

    int (*func)() = mem;
    printf("%d\n", func()); // 1

    // Self-modify: mov eax, 2
    ((unsigned char*)mem)[1] = 0x02;

    __builtin___clear_cache(mem, mem + 4096);

    printf("%d\n", func()); // 2
}