#ifdef MACRO
    ;
#endif

#ifndef MACRO
    #define MACRO 5
#endif

#if EXPRESSION
    ; // For ex. compile-time branching.
#elif OTHER_EXPRESSION
    ;
#else
    ;
#endif

#if defined(MACRO)
    ;
#endif
