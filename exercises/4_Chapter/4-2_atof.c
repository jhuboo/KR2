/*
 * atof: convert string s to double
 *       We here extend atof to handle the scientific notation
 *
 * created by Anvesh G. Jhuboo
 * on Feb/8/21
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char s[]);

int main()
{
    double n1, n2, atof(char []);
    char s1[MAXLINE] = "123.45e-3";
    char s2[MAXLINE] = "123.45e+10";

    n1 = atof(s1);
    n2 = atof(s2);

    printf("%s \t %g\n", s1, n1);
    printf("%s \t %g\n", s2, n2);

    return 0;
}

double atof(char s[])
{
    double val, power, sci_power;
    int i, sign, sci_sign;

    for (i = 0; isspace(s[i]); i++)     /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e')    /* sci notation: 123.45e-6 or 123.45e+6 */
        i++;

    sci_sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (sci_power = 0; isdigit(s[i]); i++) 
        sci_power = 10.0 * sci_power + (s[i] - '0');

    /* Handle the scientific notation sign */
    double result = sign * val / power;
    while (sci_power >= 0) {
        (sci_sign < 0) ? (result /= 10.0) : (result *= 10.0);
        --sci_power;
    }

    return result;
}
