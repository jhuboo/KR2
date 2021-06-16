/*
 * copy input to output, replacing each string of > 1 blanks by 1 blank only
 * created by Anvesh G. Jhuboo
 * on Feb/3/21
 */

#include <stdio.h>


int main()
{
    int c;
    int previous_c = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || previous_c != ' ') {
            putchar(c);
            previous_c = c;
        }
    }
}
