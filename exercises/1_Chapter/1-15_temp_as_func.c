/*
 * rewriting the temperature conversion program from 1.2 to use a function
 * for conversion
 * created by Anvesh G. Jhuboo
 * on Feb/5/21
 */

#include <stdio.h>


int fahr_celsius(int fahr);
int celsius_fahr(int celsius);

int main()
{
    /* quickly implement which one of the two function declarations are needed */
    return 0;
}

int fahr_celsius(int temperature)
{
    int celsius;

    celsius = (5.0 / 9.0) * (temperature - 32);

    return celsius;
}

int celsius_fahr(int temperature)
{
    int fahr;

    fahr = (temperature + 32) * (9.0 / 5.0);

    return fahr;
}

