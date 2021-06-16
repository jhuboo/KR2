/*
 * copy input to output, replacing tab, backspace and backslash
 * created by Anvesh G. Jhuboo
 * on Feb/3/21
 */

#include <stdio.h>


int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\b' || c == '\\') {

            putchar('\\');

            if (c == '\\')
                putchar('\\');
            if (c == '\t')
                putchar('t');
            if (c == '\b')
                putchar('b');
        }
        else {
            putchar(c);
        }
    }
}
