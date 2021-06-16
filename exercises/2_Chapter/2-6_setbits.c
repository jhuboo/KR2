/*
 * setbits: setbits(x,p,n,y) return x with the n bits that begin at position p
 *          to the rightmost n bits of y, leaving the other bits unchanged
 *
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

/* getbits: get n bits from positon p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n) & ~(~0 << n));
}

/* setbits: return x with n bits, that begin at pos p
 *          to the rightmost n bits of y, leaving other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{ 
    /* It's hard to explain but look at how the bits change stepwise
     *110101100001 -> x
     *110101011001
     *    1011

     *011011011101 -> y
     *000011011011 -> right-shift by p-n
     *111111111111 -> unary negative
     *111111110000 -> left-shift by n
     *000000001111 -> invert
     *000000001011 -> & with above
     *000001011000 -> left-shit by n & x

     *110101011001
     *     1011

     *p = 7
     *n = 4
     */
    return (x & ((y >> (p-n) & ~(~0 << n)) << n));

}


