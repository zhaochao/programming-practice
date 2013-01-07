#include <stdio.h>

/* the inverted sizeof method */
/*
int intlength(void)
{
    unsigned x = ~0;

    int i;
    for(i = 1; (x >>= 1) > 0; i++)
        ;

    return i;
}

unsigned rightrot(unsigned x, int n)
{
    int i;
    for(i = n; i > 0; i--) 
        x = (x >> 1) | ((x & 1) << (intlength() - 1));

    return x;
}
*/

/* clever solution from Greg's Cat */

unsigned rightrot(unsigned x, int n)
{
    while(n-- > 0) {
        if((x & 1) == 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x >>= 1;
    }

    return x;
}

int main(void)
{
    unsigned x = 0123;
    int n = 3;

    /*
    printf("intlength is %d.\n", intlength());
    */
    printf("rightrot(%#o, %d) is %#o.\n", x, n, rightrot(x, n));
    /* test the right shift operation of signed int */
    /*
    printf("~0 is %#o.\n", ~0);
    printf("~0U is %#o.\n", ~0U);
    printf("~0 >> 1 is %#o.\n", ~0 >> 1);
    printf("~0U >> 1 is %#o.\n", ~0U >> 1);
    printf("~(~0 >> 1) is %#o.\n", ~(~0 >> 1));
    printf("~(~0U >> 1) is %#o.\n", ~(~0U >> 1));
    */
}
