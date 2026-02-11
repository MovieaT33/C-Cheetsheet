// Linker magic symbols: https://sourceforge.net/p/predef/wiki/Architectures.
#include <string.h>

/* magic symbols */
extern char _sdata, _edata;
extern char _sbss, _ebss;

extern char _ldata;

void runtime_init(void) {
    memcpy(&_sdata, &_ldata, &_edata - &_sdata);
    memset(&_sbss, 0, &_ebss - &_sbss);
}