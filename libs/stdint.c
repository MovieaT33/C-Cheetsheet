#include <stdint.h>

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

int main(void) {
    u64 a = 0;
    i32 b = -1;
    a += (u64)(i64)b;   // a += (u64)(i64)(-1) -> a += 18446744073709551615
    return 0;
}