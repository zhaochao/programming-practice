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

/* itob: convert n to a base b character representation in s */
void itob(int n, char s[], int b)
{
    int i, sign;
    sign = n;

    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = (abs(n % b) <= 10) ? (abs(n % b) + '0') : (abs(n % b) - 10 + 'A');  /* get next digit */
    } while (n /= b);    /* delte it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


int main(void)
{
    int i = -478;
    char s1[MAX], s2[MAX], s3[MAX];

    itob(i,s1, 2);
    printf("itob(%d, 2) is %s.\n", i, s1);
    itob(i,s2, 10);
    printf("itob(%d, 10) is %s.\n", i, s2);
    itob(i,s3, 16);
    printf("itob(%d, 16) is %s.\n", i, s3);
}
