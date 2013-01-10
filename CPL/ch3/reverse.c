#include <stdio.h>
#include <string.h>

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

int main(void)
{
    char s[]="helloworld!";
    reverse(s);

    printf("after reverse(s), s is: %s\n", s);
}
