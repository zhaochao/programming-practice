#include <stdio.h>
#define MAXLINE 20    /* maxium input line length */

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len;        /* current line length */
    int max;        /* max length seen so far */
    int temp_len;     /* use for record length of lines that longer than MAXLINE */
    int getmore;    /* use for determin whether a line longer than MAXLINE */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    len = max = temp_len = getmore = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (getmore == 0) {
            if (line[len - 1] != '\n') {
                temp_len += len;
                len = 0;
                getmore = 1;
            }
        }
        else {
            /*if (line[len - 1] != '\n')
                temp_len += len;
            else {
                len += temp_len;
                temp_len = 0;
                getmore = 0;
            }*/
            temp_len += len;
            if (line[len - 1] == '\n') {
                len = temp_len;
                temp_len = 0;
                getmore = 0;
            }
        }
        if (len > max) {
            max = len;
            /*my_copy(longest, line);*/
        }
    }
    if (max > 0) {        /* there was a line */
        printf("\n------EOF------\n");
        printf("The longest line has %d characters.\n", max);
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
    /* EOF also can be the delimiter of lines.
       But EOF won't be in the string array,
       so we use '\n' instead. */
    else if (c == EOF && i > 0) {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to be big enough */
void my_copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
