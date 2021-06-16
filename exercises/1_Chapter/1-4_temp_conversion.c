/*
 * Celsius-Fahrenheit Temp Table
 * created by Anvesh G. Jhuboo
 * on Feb/3/21
 */

#include <stdio.h>

#define LOWER 0     /* lower limit */
#define UPPER 300   /* upper limit */
#define STEP  20    /* step size */

int main()
{
    int celsius;
    float fahr;

    printf("Celsius\t Fahr\n");

    for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        fahr = (9.0/5.0 * celsius) + 32;
        printf("%7d\t %4.1f\n", celsius, fahr);
    };
}
