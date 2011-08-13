#include <stdio.h>

/* print Celsius-Fahrenheit table */

main()
{
    float celsius;

    printf("Celsius\tFahr\n");  /* header */

    for (celsius = 300; celsius >= 0; celsius = celsius - 20)
        printf("%3.0f\t%6.1f\n", celsius, ((9.0 / 5.0) * celsius + 32.0));
}
