#define DEVICE_REGISTER 0x40000000

int main(void) {
    /* Value from the device will be cached to the register by the compiler.
    while (*(unsigned char*)DEVICE_REGISTER == 0)
    */

    // Prevent the optimisation.
    volatile unsigned char* device_register = (unsigned char*)DEVICE_REGISTER;
    while (*device_register == 0) ;
}