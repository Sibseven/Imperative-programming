#include <stdio.h>

int main() {
    #ifdef __TINYC__
        printf("Compiler: TCC\n");
    #elif defined __clang__
        printf("Compiler: clang\n");
    #else
        printf("Compiler: GCC\n");
    #endif

    #if defined(__x86_64__) || defined(__LP64__) || defined (__aarch64__)
        printf("Bitness: 64\n");
    #else
        printf("Bitness: 32\n");
    #endif

    #ifdef NDEBUG
        printf("Asserts: disabled\n");
    #else
        printf("Asserts: enabled\n");
    #endif

    return 0;
}