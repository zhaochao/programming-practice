#include <stdio.h>

/* find out if there is any character in
 * s2 occurs in s1. */
int any(char s1[], char s2[]) {
    int i,j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s2[j] == s1[i])
                return i;

    return -1;
}

void main() {
    char s1[]="abcdedf";
    char s2[]="1234e";

    int pos = any(s1, s2);
    if(pos != -1) {
        printf("the firset occurrence of character in both string ");
        printf("is s1[%d]: %c.\n", pos, s1[pos]);
    }
    else
        printf("No character in both string!\n");
}
