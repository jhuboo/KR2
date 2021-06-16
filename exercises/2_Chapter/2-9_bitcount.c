/*
 * bitcount: count 1 bits in x
 *
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}

/*
 * If x is odd, then (x-1) has the same bit representation as x
 * except that the rightmost 1-bit is now a 0. (x & (x-1)) == (x-1)
 *
 * If x is even, then representation is (x-1) has most rightmost zeros of x
 * becoming ones, and the rightmost one becoming a zero. Anding the twos
 * clears the rightmost 1-bit in x and all the rightmost 1-bits from (x-1)
 */
int bitcount2(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;

    return b;
}
