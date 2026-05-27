// Value will not be cached to the register

#define DEVICE_REGISTER 0x40000000

int main(void)
{
    // Prevent the optimization
    volatile unsigned char* device_register = (unsigned char*)DEVICE_REGISTER;
    while (*device_register == 0);
}