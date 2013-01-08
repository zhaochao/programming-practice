#include <stdio.h>

/* faster way to count 1 bits in x,
 * using x &= (x-1) method */
int faster_bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; b++)
        x &= (x - 1);

    return b;
}

int main(void)
{
    unsigned x = 0123;

    printf("faster_bitcount(%#o) is %d.\n", x, faster_bitcount(x));
}
