/* The proper declaration of printf is
 *      int printf(char *fmt, ...)
 *
 * Here we will implement minprintf
 * created by Anvesh G. Jhuboo
 * on Feb/18/2021
 */

#include <stdio.h>
#include <stdarg.h>


/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap;     /* points to each unnamed arg in turn */ 
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;
    void *pval;

    va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
            case 'd': case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'o':
                uval = va_arg(ap, unsigned int);
                printf("%o", uval);
                break;
            case 'x': case 'X':
                uval = va_arg(ap, unsigned int);
                printf("%x", uval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned int);
                printf("%u", uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'e': case 'E':
                dval = va_arg(ap, double);
                printf("%e", dval);
                break;
            case 'g': case 'G':
                dval = va_arg(ap, double);
                printf("%g", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'p':
                pval = va_arg(ap, void *);
                printf("%p", pval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);     /* clean up when done */
}
