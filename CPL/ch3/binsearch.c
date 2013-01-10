#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
/* original version */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else if (x < v[mid])
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

/* version of two test inside the loop */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }

    if (x == v[low])
        return low;
    else
        return -1;
}

int main(void) {
    int v[] = {2, 3, 5, 7, 9, 11};

    int x = 7;

    printf("v[%d] is %d.\n", binsearch2(7, v, 6), x);
}
