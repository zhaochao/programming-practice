#include <stdio.h>

/* use ternary operator ?: to rewrite the 
 * lower function */

int ternary_lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main(void)
{
    char c = 'N';

    printf("ternary_lower(%c) is %c.\n", c, ternary_lower(c));
}
