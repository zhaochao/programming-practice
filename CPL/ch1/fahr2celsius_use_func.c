#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
float f2c(float f)
{
    float c;
    c = (5.0 /9.0) * (f - 32.0);

    return c;
}

main()
{
    float fahr;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f\t%6.1f\n", fahr, f2c(fahr));
        fahr = fahr + step;
    }
}
