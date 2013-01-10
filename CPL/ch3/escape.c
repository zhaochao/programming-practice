#include <stdio.h>

#define MAX 100

/* escape: convert invisible characters to
 * escape sequences. */

int escape(char s[], char t[])
{
    int i,j;
    for(i=0, j=0; s[i] != '\0'; i++,j++) {
        switch (s[i]) {
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                break;
            case '\r':
                t[j] = '\\';
                t[++j] = 'r';
                break;
            case '\v':
                t[j] = '\\';
                t[++j] = 'v';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
}

int main(void)
{
    char s[MAX]="abc\tdef\nghi\rjkl\v";
    char t[MAX];

    escape(s,t);
    printf("s is %s.\n", s);
    printf("t is %s.\n", t);
}
