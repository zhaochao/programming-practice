#include <stdio.h>

/* replace one or more blank by single blank in input */
main()
{
    int c, check;
    
    check = 0;

    while ((c = getchar()) != EOF)
    {
        if (((c == ' ') && (check != ' ' )) || (c != ' '))
        {
            check = c;
            putchar(c);
        }
    }
}
