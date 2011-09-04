#include <stdio.h>
#define MAXLINE 40  /* maxium input line length */
#define LIMIT 30    /* lines longer than this limit should be printed */

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

/* print length of the longest line input ,
   and as much as possible characters. */
main()
{
    int len;        /* current line length */
    int temp_len;   /* store temp length of lines longer than MAXLINE */
    int getmore;    /* determine whether a line ended not */
    char line[MAXLINE];     /* current input line */
    char first_part[MAXLINE];  /* storage first part of current line */

    len = temp_len = getmore = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (getmore == 0) {
            if (line[len - 1] != '\n') {
                my_copy(first_part, line);
                temp_len += len;
                len = 0;
                getmore = 1;
            }
        }
        else {
            temp_len += len;
            if (line[len - 1] == '\n') {
                len = temp_len;
                temp_len = 0;
                getmore = 0;
            }
        }
    if (len > LIMIT) {      /* print lines */
        printf("%s", first_part);
    }
    }
    return 0;
}

/* my_getline: read a line into s, retrun length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

/* my_copy: copy 'from' into 'to'; assume to be big enough */
void my_copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
