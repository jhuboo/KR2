/*
 * invert: return 'x' with the 'n' bits that begin at position 'p' inverted
 *         leaving other bits unchanged
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    /*11011001 -> x
     *00110110 -> right-shift by p-n
     *11111111 -> unary inversion
     *11111000 -> left-shift by n
     *00000111 -> invert
     *00000110 -> or with step 2
     *00011000 -> left-shift by p-n
     *11000101 -> xor with x
     *
     *
     *
     *11000101 -> final inverted
     *iii001ii
     *
     *p = 5
     *n = 3
     */
    return (x ^ ((x >> (p-n) | ~(~0 << n)) << (p-n)));
}

