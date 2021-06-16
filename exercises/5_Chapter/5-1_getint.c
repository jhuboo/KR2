#include <stdio.h>
#include <ctype.h>
#include "hdr.h"

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pm */
int getint(int *pn)
{
    int c, sign;

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

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}
