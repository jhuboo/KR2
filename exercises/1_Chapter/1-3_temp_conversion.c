/*
 * temp_conversion.c
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 * created by Anvesh G. Jhuboo
 * on 2/3/21
 */

#include <stdio.h>

int main()
{
    int fahr, celsius;
    
    int lower = 0;      /* lower limit of temp table */
    int upper = 300;    /* upper limit of temp table */
    int step = 20;      /* step size */

    printf("Fahr\t Celsius\n");     /* Heading for table */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%4d\t %6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
