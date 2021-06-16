/*
 * rightrot: return the value of the integer 'x' rotated by the right
 *           by n bit positions
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>
#include <ctype.h>

unsigned rightrot(unsigned x, int n)
{
    /*1011001 -> x
     *0001011 -> x >> n
     *
     *0010000 -> x << (sizeof(x) - 3), xor with step 2
     *0011011 -> final x,
     * n = 3
     */
    return ((x >> n) ^ (x << (sizeof(x) - n)));
}
