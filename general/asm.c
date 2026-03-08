/* GCC assembly example:
asm ( assembler_template 
    : output_operands     // optional
    : input_operands      // optional
    : clobbered_registers // optional
);

See here more:
https://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/Constraints.html#Constraints
*/

asm("nop");

int main(void) {
    // No operation:
    asm volatile ("nop"); // `volatile` to prevent optimization.

    // Move 10 into x using a register:
    int x = 5;
    __asm__ ("movl $10, %0" : "=r" (x));

    int a = 3, b = 4, sum;

    asm ("addl %1, %0"
         : "=r" (sum)           // output
         : "r" (b), "0" (a));   // inputs: "0" reuses the same register as sum.

    int x = 5;
    asm volatile ("inc %0"
                  : "+r" (x)    // read/write
                  : 
                  : "cc");      // "cc" = condition codes (flags)

    return x; // 10
}