/* Discussion
 *
 * In a two complement number system representation,
 * this version of itoa doesn't handle the largest neg num
 * where n = -2^(wordsize-1)
 *
 * Reason for this is:
 * for signed int, say on an 8-bit computer
 * -128 <= int < 127
 *
 * The rule of complements!
 * Important to notice that on 8-bit computer
 * the repr is from -128 to 127
 * as opposed to    -127 to 127
 * Therefore, the abs value of the largest neg num cannot be represented
 * because it's complement will be subtracted by 1
 *
 *                  SIGNED          UNSIGNED
 * In binary repr: -128 -> 10000000 <- 128 
 *                  127 -> 01111111 <- 127
 *                   25 -> 00011001 <-  25
 *                  -25 -> 11100110 <- 230
 *                  001 -> 00000001 <- 001
 *                   -1 -> 11111110 <- 254
 *                  000 -> 00000000 <- 000
 *                  255 -> 11111111 <- 255
 *
 * To fix this bug
 * 1. change while ((n /= 10) > 0) to while (n /= 0)
 * 2. change 'n % 10 + '0'' to 'abs(n % 10) + '0''
 */ 

#include <stdlib.h>

/* itoa: convert n to characters in s */

void itoa(int n, char s[])
{
    int i, sign;

    while ((sign = n) < 0)  /* record sign */
        n = -n;             /* make n positive */

    i = 0;
    do {    /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';    /* get the digit */
    } while ((n /= 10));            /* delete it */

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
