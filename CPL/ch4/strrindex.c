#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;
    int rightmost = 0;

    while (my_getline(line, MAXLINE) > 0)
        if ((rightmost = strrindex(line, pattern)) >= 0) {
            printf("%s", line);
            printf("%d\n", rightmost);
            found++;
        }
    return found;
}

/* my_getline: get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return the rightmost occurrence of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, last_occur;

    last_occur = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            last_occur = i;
    }

    return last_occur;
}
