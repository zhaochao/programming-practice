#include <stdio.h>

/* replace tabs in input with spaces and
 * keep the same spacing */
#define MAXLINE 1000       /* max length of lines in input */
#define TAP_STOPS 4         /* fixed set of tab stops */

int my_getline(char line[], int maxline);

main()
{
    int i, j;          /* temp index */
    int len;        /* current line length */
    int spacecount;     /* how many spaces for replacing tab */
    char line[MAXLINE];     /* current input line */
    int pos;        /* position in output */

    pos = 0;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        for (i = 0; i < len; i++) {
            if (line[i] != '\t')
                putchar(line[i]);
                pos ++;
            else {
                /*spacecount = TAP_STOPS - (i % TAP_STOPS);*/
                spacecount = TAP_STOPS - (pos % TAP_STOPS);
                for(j = 0; j < spacecount; j++)
                    putchar(' ');
                pos += spacecount;
            }
        }
    }

    return 0;
}

/* my_getline: read a line int s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
