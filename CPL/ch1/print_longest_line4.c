#include <stdio.h>
#define MAXLINE 20  /* maxium input line length */

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

/* print length of the longest line input ,
   and as much as possible characters. */
main()
{
    int len;        /* current line length */
    int temp_len;   /* store temp length of lines longer than MAXLINE */
    int getmore;    /* determine whether a line ended not */
    int max;        /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    char temp_first_part[MAXLINE];  /* storage first part of lines longer than MAXLINE */

    len = temp_len = max = getmore = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (getmore == 0) {
            if (line[len - 1] != '\n') {
                my_copy(temp_first_part, line);
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
        if (len > max) {
            max = len;
            my_copy(longest, temp_first_part);
        }
    }
    if (max > 0) {      /* there was a line */
        printf("\n------EOF------\n");
        printf("The longest line has %d characters.\n", max);
        printf("But I can just print %d of them: \n", MAXLINE);
        printf("%s", longest);
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
