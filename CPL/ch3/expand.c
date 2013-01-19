#include <stdio.h>

#define MAX 1000

int expand(char s1[], char s2[])
{
    int i, j, k;

    for(i=0, j=0; s1[i] != '\0' && i < MAX && j < MAX; i++) {
        if (s1[i] == '-')
            if (i >= 1 && s1[i+1] != '\0')
                if (s1[i-1] >= 'a' && s1[i-i] <= 'z' && s1[i+1] > s1[i-1] && s1[i+1] <= 'z') {
                    j--;
                    for (k=0; k < (s1[i+1] - s1[i-1]) && j < MAX; k++)
                        s2[j++] = s1[i-1] + k;
                    continue;
                }
                else if (s1[i-1] >= 'A' && s1[i-i] <= 'Z' && s1[i+1] > s1[i-1] && s1[i+1] <= 'Z') {
                    j--;
                    for (k=0; k < (s1[i+1] - s1[i-1]) && j < MAX; k++)
                        s2[j++] = s1[i-1] + k;
                    continue;
                }
                else if (s1[i-1] >= '0' && s1[i-1] <= '9' && s1[i+1] > s1[i-1] && s1[i+1] <= '9'){
                    j--;
                    for (k=0; k< (s1[i+1] - s1[i-1]) && j < MAX; k++)
                        s2[j++] = s1[i-1] + k;
                    continue;
                }
        
        if (j < MAX)
            s2[j++] = s1[i];
    }
}

int main(void)
{
    char s1[MAX] = "-1-3-5a-c-A-D-";
    char s2[MAX];

    expand(s1, s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
}
