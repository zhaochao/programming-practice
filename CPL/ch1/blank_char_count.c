#include <stdio.h>

/* count blanks, tabs, newlines in input */
main()
{
    int c, nb, nt, nl;
    
    nb = nt = nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("Total blanks: %d.\n", nb);
    printf("Total tabs: %d.\n", nt);
    printf("Total newlines: %d.\n", nl);
}
