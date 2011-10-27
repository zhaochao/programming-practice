#include <stdio.h>

/* remove comments in c program. */

main()
{
    int c;      /* the current character in input */

    /* switch to state if the current
     * character is in comment or 
     * single quote or double quote. */
    int in_comment, in_s_quote, in_d_quote;
    /* switch to tell whether the character
     * before the current on is slash or star */
    int bef_is_slash, bef_is_star;

    in_comment = in_s_quote = in_d_quote = 0;
    bef_is_slash = bef_is_star = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\'') {
            if (! in_s_quote)
                in_s_quote = 1;
            else
                in_s_quote = 0;

            putchar(c);
        }
        else if (c == '"') {
            if (! in_d_quote)
                in_d_quote = 1;
            else
                in_d_quote = 0;

            putchar(c);
        }
        else if ((! in_s_quote) && (! in_d_quote)) {
            if (c == '*' && bef_is_slash)
                in_comment = 1;
            else if (c == '/' && bef_is_star)
                in_comment = 0;

            if (! in_comment) {
                if (c == '/') {
                    if (bef_is_slash)
                        putchar('/');

                    bef_is_slash = 1;
                }
                else if (c == '*') {
                    if (bef_is_star)
                        putchar('*');

                    bef_is_star = 1;
                }
                else {
                    if (bef_is_slash) {
                        putchar('/');
                        bef_is_slash = 0;
                    }
                    else if (bef_is_star) {
                        putchar('*');
                        bef_is_star = 0;
                    }

                    putchar(c);
                }
            }
        }
    }

    return 0;
}
