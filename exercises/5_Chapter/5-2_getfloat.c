#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "hdr.h"

int getch(void);
void ungetch(int);

/* getfloat: get next integer from input into *pm */
double getfloat(int *pn)
{
    int c, sign, fraction;

    while (isspace(c = getch()))    /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     /* It's not a number */ 
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();        /* Read next char */
        if (!isdigit(c)) {
            ungetch(sign == -1 ? '-' : '+'); /* pushback on buffer */
            return 0;
        }
    }

    for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
        if (c == '.')
            fraction = 1;
        else
            if (!fraction)
                *pn = 10 * *pn + (c - '0');
            else {
                *pn = *pn + ((c - '0') / pow(10, fraction));
                fraction++;
            }
    }
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}
