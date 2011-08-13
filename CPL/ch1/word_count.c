#include <stdio.h>

/* count lines, words, characters in input. */
#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
        printf("total lines: %d.\n", nl);
        printf("total words: %d.\n", nw);
        printf("total characters: %d.\n", nc);
}
