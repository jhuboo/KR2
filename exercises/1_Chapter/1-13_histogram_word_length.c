/*
 * Print horizontal histogram of the lengths of words in its input
 * created by Anvesh G. Jhuboo
 * on Feb/4/21
 */

#include <stdio.h>

#define IN  1           /* inside a word */
#define OUT 0           /* outside a word */
#define MAXWORDLEN  10  /* max world length for historgram */


int main()
{
    int c, i, j, nc;
    int words[MAXWORDLEN + 1];

    int state = IN;        /* starts IN a word */

    /* populate words arr */
    for (i = 0; i < MAXWORDLEN; i++)
        words[i] = 0;

    /* take input till whitespace, and add it to subarr */
    nc = 0;
    while ((c = getchar()) != EOF) {

        ++nc;   /* incremement new character */

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            --nc;
        }
        
        if (state == OUT) {
            if (nc != 0 && nc <= MAXWORDLEN)
                ++words[nc];    /* add it to the subarr */

            state = IN;
            nc = 0;
        }
    }

    printf("\n\nHistorgram of words in input\n\n");
    for (i = 1; i <= MAXWORDLEN; i++) {

        printf("|%d\t|%2d| ", words[i], i);

        for (j = 0; j < words[i]; j++)
            putchar('*');

        putchar('\n');
    }
}
