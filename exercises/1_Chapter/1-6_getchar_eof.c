/*
 * Verifying that expression getchar() != EOF is 0 or 1
 * created by Anvesh G. Jhuboo
 * on Fe/3/21
 */

#include <stdio.h>

int main()
{
    int c = getchar() != EOF;
    int d = getchar() == EOF;

    printf("%d\t %d\n", c, d);
} 
