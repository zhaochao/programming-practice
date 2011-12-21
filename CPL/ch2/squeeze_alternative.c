#include <stdio.h>

#define YES 1
#define NO 0

/* squeeze: detele each character in the first string
 * that matches any character in the second string. */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int in_second;

    i = 0;
    in_second = NO;
    
    while(s1[i] != '\0') {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                in_second = YES;
        }

        if (in_second == NO)
            s1[i++] = s1[i];
        else {
            for (k = i; s1[k] != '\0'; k++) 
                s1[k] = s1[k + 1];

            in_second = NO;
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
