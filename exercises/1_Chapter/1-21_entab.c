/*
 * entab: replaces string of blanks by the minimum no of tabs and blanks
 * needed to achieve the same spacing
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB 4       /* TAB size */

int main()
{
    int c, i;

    i = 0;

    while ((c = getchar()) != EOF) {

        if (c == '\n')
            i = 0;      /* reset column counter */

        if (c == ' ') {
            i++;
            if ((i % TAB) == 0) {
                putchar('\t');
                i = 0;
            } else {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}

