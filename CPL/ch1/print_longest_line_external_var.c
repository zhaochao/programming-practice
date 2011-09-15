#include <stdio.h>
#define MAXLINE 1000    /* maxium input line length */

int max;                /* max length so far */
char line[MAXLINE];     /* current input line */
char longest[MAXLINE];  /* longest line saved here */

int my_getline(void);
void my_copy(void);

/* print the longest input line, specialized version */
main()
{
    int len;        /* current line length */
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = my_getline()) > 0)
        if (len > max) {
            max = len;
            my_copy();
        }
    if (max > 0) {        /* there was a line */
        printf("\n------EOF------\n");
        printf("The longest line is:\n");
        printf("%s", longest);
    }
    return 0;
}

/* my_getline: read a line into s, return length, specialized version */
int my_getline()
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to be big enough, specialized version */
void my_copy()
{
    int i;
    extern char line[];
    extern char longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
