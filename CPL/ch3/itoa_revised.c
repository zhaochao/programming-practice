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

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    sign = n;

    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while (n /= 10);    /* delte it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main(void)
{
    int i = 478;
    int j = -5093;
    int k = INT_MIN;
    char s1[MAX], s2[MAX], s3[MAX];

    itoa(i,s1);
    printf("itoa(%d) is %s.\n", i, s1);
    itoa(j,s2);
    printf("itoa(%d) is %s.\n", j, s2);
    itoa(k,s3);
    printf("itoa(%d) is %s.\n", k, s3);
}
