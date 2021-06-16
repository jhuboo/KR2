/*
 * detab: replaces tab in the input with the proper number of blanks to space
 * to the next tab stop.
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB 4       /* TAB length */

int main()
{
    int c, i;

    i = 0;

    while ((c = getchar()) != EOF) {
        i++;

        if (c == '\n')
            i = 0;      /* reset column counter */

        if (c == '\t') {
            while ((i % TAB) != 0) {
                putchar(' ');
                i++;
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
