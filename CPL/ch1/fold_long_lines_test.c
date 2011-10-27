#include <stdio.h>

/* fold long input lines into two or
 * more shorter lines. */

#define MAXLINE 1000        /* max length of lines in input */
#define FOLDLENGTH 20       /* The max length of lines in output */

int my_getline(char line[], int maxline);

main()
{
    int i_idx, o_idx;       /* index of input and output */
    int blank_holder;       /* the position of spaces and tabs  in input */
    char line[MAXLINE];     /* current input line */
    int len;                /* length of current input line */
    
    while ((len = my_getline(line, MAXLINE)) > 0 ) {
        o_idx = blank_holder = 0;
        for (i_idx = 0; i_idx < len; i_idx++) {
            if (line[i_idx] == ' ' || line[i_idx] == '\t')
                blank_holder = i_idx;
            if (o_idx == FOLDLENGTH) {
                if (blank_holder > 0)
                    line[blank_holder] = '\n';
                o_idx = 0;
            }
            o_idx++;
        }

        printf("%s", line);
    }

    return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
