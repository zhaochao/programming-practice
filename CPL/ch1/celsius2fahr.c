#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for celsius = 0, 20, ..., 300; floating-point version */
main()
{
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;    /* lower limit of temperature scale */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    celsius = lower;
    printf("Celsius\tFahr\n");  /* header */
    while (celsius <= upper) {
        fahr = (9.0 / 5.0 ) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
