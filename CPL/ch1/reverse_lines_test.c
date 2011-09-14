#include <stdio.h>
#define MAXLINE 1001    /* maxium input line length */

int my_getline(char line[], int maxline);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char r_line[MAXLINE];   /* reversing version of current input line */
    int i;          /* temp array index */

    len = i = 0;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        for (i = 0; i < len; i++) {
            r_line[i] = line[len -1 - i];
        }
        r_line[i] = '\0';
        
        printf("%s", r_line);
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
