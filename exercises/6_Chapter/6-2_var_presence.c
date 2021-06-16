/* Take advantage of the fact that a binary tree is printed in order
 * If n chars of a series are similar, then by nature of the binary tree
 * they will be printed in order. Thefore, we only need to keep track of
 * when the comparisons are similar to print the series.
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/2021
 */
#include <stdio.h>
#include <stdlib.h>

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};


/* mystrcmp: returns 1 if s1 & s2 are similar, otherwise 0 */
int mystrcmp(char *s1, char *s2, int n)
{
    int i;

    if (n == 0)
        return 1;

    for (i = 0; *s1 == *s2 && *s1 != '\0' && i < n; *s1++, *s2++)
        ;

    if (i == n)
        return 1;
    else
        return 0;
}

/* mytreeprint: in order print of tree p */
void mytreeprint(struct tnode *p, int n)
{
    static int printprevious = 1;   /* flag to prev node */
    static struct tnode *previous;

    if (p != NULL) {
        mytreeprint(p->left, n);

        if (n == 0)     /* if n == 0, print all nodes */
            printf("%4d %s\n", p->count, p->word);

    } else {
        if (previous != NULL) {

            /* returns 1 if first n chars are identical */
            if (mystrcmp(previous->word, p->word, n)) {

                if (printprevious) {
                    printf("%4d %s\n", previous->count, previous->word);

                    /* when previous has been printed, no need to
                     * print again until a new series is encountered */
                    printprevious = 0;
                }

                printf("%4d %s\n", p->count, p->word);

            } else
                /* if comparison is no longer true,
                 * reset printprevious to get ready for next series */
                printprevious = 1;
        }

        /* keep track of pointers to previous encountered node
         * for comparison */
        previous = p;

    }

    mytreeprint(p->right, n);
}
