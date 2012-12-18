#include <stdio.h>

/* change n bits of x from position p to the
 * rightmost n bits of y */
int setbits(unsigned x, int p, int n, unsigned y) {
    /*
    return x & ~(~(~0 << n) << (p + 1 - n)) | 
        (y & ~(~0 << n)) << (p + 1 - n);
    */
    /* another expression */
    /*
    return x & ((~0 << (p + 1) | ~(~0 << (p + 1 - n)))) |
        (y & ~(~0 << n)) << (p + 1 - n);
    */
    /* yet another one */
    return (x | (~(~0 << n ) << (p + 1 - n))) &
        ((y << (p + 1 - n)) | ~(~(~0 << n ) << (p + 1 - n)));
}

void main() {
    int x = 0777;
    int p = 5;
    int n = 3;
    int y = 01;

    printf("setbits(%#o, %d, %d, %#o) = %#o.\n", x, p, n, y, setbits(x, p, n, y));
} 
