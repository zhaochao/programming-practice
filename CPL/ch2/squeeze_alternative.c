#include <stdio.h>

/* squeeze: detele each character in the first string
 * that matches any character in the second string. */
void squeeze(char s1[], char s2[])
{
    int i, j;
    i = 0;
    
    while(s1[i] != '\0') {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                s1[i] = s1[++i];
        }
    }
}

void main()
{
    char s[] = "ab12cd34ef56";
    char c[] = "a1";

    squeeze(s,c);
    printf("%s", s);
}
