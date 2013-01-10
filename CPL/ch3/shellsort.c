#include <stdio.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

int main(void)
{
    int v[] = {23, 4 ,6, 78, 92, 57, 1, 10, 47, 88};

    shellsort(v, 10);

    printf("after shellsort(v, 10), v[] is:\n");
    int i;
    for (i=0; i < 9; i++)
        printf("%d ", v[i]);
    printf("%d.\n", v[i]);
}
