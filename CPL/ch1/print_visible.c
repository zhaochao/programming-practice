#include <stdio.h>

/* make blank, tabs, / visible in input */
main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            printf("\\t");
        if (c == '\b')
            printf("\\b");
        if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}
