/*
 * fold: fold input lines into two or more shorter lines after last non-blank
 *       occurs before the n-th column of input
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

#define FOLD    40      /* fold length, feel free to modigy */

int main()
{
    int c, i;

    i = 0;

    while ((c = getchar()) != EOF) {
        ++i;
        putchar(c);

        if (i > FOLD) {
            putchar('\n');  /* fold the line by adding a newline char */
            i = 0;          /* reset the column */
        }
    }

    return 0;
}
