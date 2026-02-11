#include <stdio.h>

int main() {
    // Standard C preprocessor macros:
    printf("__BASE_FILE__ = %s\n", __BASE_FILE__);
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Function: %s\n", __func__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("STDC version: %ld\n", __STDC_VERSION__);

#if __STDC_HOSTED__
    printf("__STDC_HOSTED__ = 1 (hosted, full C library)\n");
#else
    printf("__STDC_HOSTED__ = 0 (freestanding, limited environment)\n");
#endif

#if __STDC_MB_MIGHT_NEQ_WC__
    printf("__STDC_MB_MIGHT_NEQ_WC__ = 1 (multibyte != wide char)\n");
#else
    printf("__STDC_MB_MIGHT_NEQ_WC__ = 0\n");
#endif

#if __has_include(<math.h>)
    #include <math.h>
    printf("__has_include(<math.h>) = true\n");
#else
    printf("__has_include(<math.h>) = false\n");
#endif

#if __has_builtin(nonexistent_builtin)
    printf("__has_builtin(nonexistent_builtin) = true\n");
#else
    printf("__has_builtin(nonexistent_builtin) = false\n");
#endif

#ifdef __GNUC__
    printf("Include level: %d\n", __INCLUDE_LEVEL__);
    printf("Counter: %d\n", __COUNTER__);
#endif

    return 0;
}