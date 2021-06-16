/*
 * program that prints input one word per line
 * created by Anvesh G. Jhuboo
 * on Feb/3/21
 */

#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

int main()
{
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF) {

        if (c != ' ' && c != '\n') {
            if (state == OUT)
                state = IN;

            putchar(c);
        }
        else if (state == IN) {
            state = OUT;
            putchar('\n');
        }
    }
}
