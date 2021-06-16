/* postfix calculator: rewriting getop
 *
 * created by Anvesh G. Jhuboo
 * on Feb/18/2021
 */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'      /* signal number is found */


/* getop: get next operator or next operand */
int getop(char s[])
{
    int c, rc;
    float f;

    while ((rc = scanf("%lc", &c)) != EOF)
        if ((s[0] = c) != ' ' && c != '\t')
            break;

    s[1] = '\0';

    if (rc == EOF)
        return EOF;
    else if (!isdigit(c) && c != '.')
        return c;

    ungetc(c, stdin);   /* if c is digit or decimal, push back onto input */
    scanf("%f", &f);        /* read num */
    sprintf(s, "%f", f);    /* convert f into char string s */

    return NUMBER;
}

