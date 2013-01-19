#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 1000

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        /* c = s[i], s[i] = s[j], s[j] = c; */
    }
}

/* itoa_pad: convert n to characters in s with a minimum field width */
void itoa_pad(int n, char s[], int w)
{
    int i, j, sign;
    sign = n;

    i = j = 0;
    do {        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while (n /= 10);    /* delte it */

    if (sign < 0)
        s[i++] = '-';
    /*
    if (i < w)
        for (j=0; j < (w-i); j++)
            s[i++] = ' ';
    */
    /* direct and clever solution */
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}


int main(void)
{
    int i = 478;
    int j = -5093;
    int k = INT_MIN;
    int w = 10;
    char s1[MAX], s2[MAX], s3[MAX];

    itoa_pad(i,s1,w);
    printf("%s.\n", s1);
    itoa_pad(j,s2,w);
    printf("%s.\n", s2);
    itoa_pad(k,s3,w);
    printf("%s.\n", s3);
}
