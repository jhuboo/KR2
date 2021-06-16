/* A small version of scanf
 * minscanf(char *format, ...)
 *
 * created by Anvesh G. Jhuboo
 * on Feb/18/2021
 */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100


/* scanf: reads stdin, storing input in args according to format */
void minscanf(char *format, ...)
{
    va_list ap;     /* point to each unnamed arg in turn */
    char localfmt[LOCALFMT];
    char *p, *sval;
    int *ival;
    unsigned *uval;
    double *dval;
    int c, i;

    i = 0;      /* idx for localfmt array */
    va_start(ap, format);   /* make ap point to 1st unnamed arg */

    for (p = format; *p; p++) {
        if (*p != '%') {
            localfmt[i++] = *p;     /* collect chars */
            continue;
        }

        localfmt[i++] = '%';        /* start format */
        while (*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *++p;   /* collect chars */ 
        localfmt[i++] = *(p+1);     /* format letter */
        localfmt[i]   = '\0';

        switch (*++p) {
            case 'd': case 'i': case 'c':
                ival = va_arg(ap, int *);
                scanf(localfmt, ival);
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf(localfmt, dval);
                break;
            case 'x': case 'X': case 'o': case 'u':
                uval = va_arg(ap, unsigned *);
                scanf(localfmt, uval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(localfmt, sval);
                break;
            default:
                scanf(localfmt);
                break;
        }
        i = 0;      /* reset index */
    }

    va_end(ap);     /* clean up */
}
