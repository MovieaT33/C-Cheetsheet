#include <stdio.h>
#include <stdint.h>
#include <string.h>

static inline void hot_path(void) {
    puts("hot path");
}

static inline void cold_path(void) {
    puts("cold path");
}

int demo(int *ptr, uint32_t x, uint32_t y) {
    /* __builtin_expect */
    if (__builtin_expect(ptr != NULL, 1)) {
        hot_path();
    } else {
        cold_path();
        __builtin_unreachable();
    }

    /* __builtin_prefetch */
    __builtin_prefetch(ptr, 0, 3);

    /* __builtin_memcpy / memset */
    int a[4];
    __builtin_memset(a, 0, sizeof(a));

    int b[4] = {1, 2, 3, 4};
    __builtin_memcpy(a, b, sizeof(a));

    /* __builtin_clz / ctz / popcount */
    int lz  = __builtin_clz(x);       // leading zeros
    int tz  = __builtin_ctz(x);       // trailing zeros
    int pc  = __builtin_popcount(x);

    /* __builtin_bswap32 */
    uint32_t swapped = __builtin_bswap32(x);

    /* __builtin_add_overflow */
    uint32_t sum;
    if (__builtin_add_overflow(x, y, &sum)) {
        puts("overflow detected");
    }

    /* __builtin_types_compatible_p */
    if (__builtin_types_compatible_p(int, int)) {
        puts("int == int");
    }

    /* __builtin_choose_expr (compile-time if) */
    int val = __builtin_choose_expr(
        sizeof(void*) == 8,
        64,   // 64-bit
        32    // 32-bit
    );

    /* __builtin_return_address / frame_address */
    void *ret = __builtin_return_address(0);
    void *frm = __builtin_frame_address(0);

    printf("lz=%d tz=%d pop=%d swap=0x%x sum=%u val=%d\n",
           lz, tz, pc, swapped, sum, val);
    printf("return=%p frame=%p\n", ret, frm);

    return a[0];
}

void smc_demo(void *code, size_t size) {
    /* __builtin___clear_cache */
    __builtin___clear_cache((char*)code, (char*)code + size);

    /* __builtin_trap */
    __builtin_trap(); // SIGILL / abort-like
}

int main(void) {
    int x = 0x00F0F000;
    demo(&x, x, 1);
    __extension__ __int128 huge_num;
    return 0;
}