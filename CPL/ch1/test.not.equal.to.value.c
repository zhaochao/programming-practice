#include <stdio.h>

/* test the != expression value */
main()
{
    int c;

    while (c = getchar() != EOF)
        printf("the value of the expression \"getchar() != EOF\" is %d.\n", c);
}
