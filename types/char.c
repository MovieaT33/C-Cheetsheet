#include <wchar.h>
#include <uchar.h>

int main(void) {
    // Character literal transforms to integer by ASCII table.
    char character = 'A';
    char character = "A";   // Error, double quotes for strings.

    // Special characters: \n, \t, \r, \0, \', \", \\, \a, \b, \f, \v
    // POSIX: \033[0m, \033[H\033[J, \033[r;g;b;m etc.

    char char_ = "Hi"[0];

    char c = 'A';
    wchar_t wc = L'Ω';
    char16_t c16 = u'あ';
    char32_t c32 = U'𠜎';
    const char *utf8 = u8"Hello";

    return 0;
}