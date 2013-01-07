#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - n + 1));
}

int main(void)
{
    unsigned x = 0123;
    int p = 5;
    int n = 3;

    printf("invert(%#o, %d, %d) = %#o.\n", x, p, n, invert(x, p, n));
}
