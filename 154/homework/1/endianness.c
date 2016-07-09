#include <stdio.h>
#include <limits.h>

typedef unsigned int uint;

int main()
{
    int endian, foo;

    foo = 1;
    // we need to see what's in memory... point to the first byte of foo
    // (char = byte) and see what the first item in memory is.
    // Return 1 if big, 0 if little endian
    endian = ((int) (*((char*)&foo))) == 0 ? 1 : 0;

    printf("hello world, from a %s-endian machine\n", endian ? "big" : "little");

    /* A. At least one bit of x is 0.
     * B. At least one bit of x is 1.
     * C. Any of the bits in the most significant nibble of x is 0.
     * D. Any of the bits in the least significant nibble of x is 1.
     * E. The most significant and the least significant byte are equal. For this part equality (==) testing is allowed.
     * F. Any even bit of x is 1. The least-significant bit is an even bit, for example. For this part you can assume
     * an int is 32-bits
     */
    int x = 0xFFF00000;
    printf("A:%i\n", !!(x ^ 0xFFFFFFFF));
    printf("B:%i\n", !!(x ^ 0));
    printf("C:%i\n", !!(((uint)(x) >> 28) ^ 0x0000000F));
    printf("D:%i\n", !!(((uint)x << 28) ^ 0xF0000000));
    printf("E:%i\n", !!(((uint)x >> 24) ^ ~((uint)x << 24 >> 24)));
    printf("F:%i\n", !!(((uint)x & 1) || (((uint)x >> 2) & 1) || (((uint)x >> 4) & 1) || (((uint)x >> 6) & 1) ||
                       (((uint)x >> 8) & 1) || (((uint)x >> 10) & 1) || (((uint)x >> 12) & 1) || (((uint)x >> 14) & 1) ||
                       (((uint)x >> 16) & 1) || (((uint)x >> 18) & 1) || (((uint)x >> 20) & 1) || (((uint)x >> 22) & 1) ||
                       (((uint)x >> 24) & 1) || (((uint)x >> 26) & 1) || (((uint)x >> 28) & 1) || (((uint)x >> 30) & 1)));

    return endian;
}
