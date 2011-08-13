#include <stdio.h>

/* print input one work per line */
#define IN 0    /* inside a word */
#define OUT 1   /* outside a word */

main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if ((c != ' ') && (c != '\t') && (c != '\n')) {
            state = IN;
            putchar(c);
        }
        else if (state == IN) {
            printf("\n");
            state = OUT;
        }
    }
}
