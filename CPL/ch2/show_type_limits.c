#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
    printf("Size of char is: %d.\n", CHAR_BIT);
    printf("Max of char is: %d.\n", CHAR_MAX);
    printf("Min of char is: %d.\n", CHAR_MIN);
    printf("Max of int is: %d.\n", INT_MAX);
    printf("Min of int is: %d.\n", INT_MIN);
    printf("Max of long is: %ld.\n", LONG_MAX);
    printf("Min of long is: %ld.\n", LONG_MIN);
    printf("Max of short is: %d.\n", SHRT_MAX);
    printf("Min of short is: %d.\n", SHRT_MIN);
    printf("Max of unsigned char is: %u.\n", UCHAR_MAX);
    printf("Max of unsigned int is: %u.\n", UINT_MAX);
    printf("Max of unsigned long is: %lu.\n", ULONG_MAX);
    printf("Max of unsigned short is: %u.\n", USHRT_MAX);
    printf("Max of float is: %f.\n", FLT_MAX);
    printf("Min of float is: %f.\n", FLT_MIN);
    printf("Max of double is: %f.\n", DBL_MAX);
    printf("Min of double is: %f.\n", DBL_MIN);
    printf("Max of long double is: %Lf.\n", LDBL_MAX);
    printf("Min of long double is: %Lf.\n", LDBL_MIN);
}
