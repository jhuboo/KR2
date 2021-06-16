/* Cross-referencer program:
 * Print a list of all words in a document, and, for each word, a list of
 * the line numbers on which it occurs. Remove noise words like "the", "and"
 * and so on.
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/2021
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 16     /* max lines to count for each word */

struct tnode {
    char *word;                 /* pointer to text */
    struct tnode *left;         /* left child */
    struct tnode *right;        /* right child */
    unsigned lines[MAXLINES];   /* line numbers */
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
char *getword();
int isnoise(char *);
char *strdup(char *);


/* cross-referencer */
int main()
{
    struct tnode *root;
    char *word;
    unsigned int line = 1;

    root = NULL;
    while ((word = getword()) != NULL)
        if (isalpha(word[0]) && !isnoise(word))
            root = addtree(root, word, line);
        else if (word[0] == '\n')
            line++;

    treeprint(root);
    return 0;
}


/* isnoise: test if word is a noise word */
int isnoise(char *word)
{
    static char *noise[] = {
        "a", 
        "an",
        "and",
        "are",
        "for",
        "from",
        "in",
        "is",
        "it",
        "not",
        "of",
        "on",
        "or",
        "that",
        "the",
        "this",
        "to",
        "very",
        "was",
        "with",
    };

    int cond;
    int low, high, mid;

    if (word[1] == '\0')
        return 1;

    low = 0;
    high = sizeof(noise) / sizeof(char *) - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, noise[mid])) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return 1;
    }

    return 0;
}


/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int l)
{
    int cond;
    int i;

    /* if a new word has arrived, make a new node */
    if (p == NULL) {
        p = (struct tnode *) malloc(sizeof(struct tnode));

        p->word = strdup(w);
        p->lines[0] = l;

        for (i = 1; i < MAXLINES; i++)
            p->lines[i] = 0;

        p->left = p->right = NULL;

    } else if ((cond = strcmp(w, p->word)) == 0) {  /* repeated word */
        for (i = 0; p->lines[i] && i < MAXLINES; i++)
            p->lines[i] = l;

    } else if (cond < 0)    /* less than current word */
        p->left = addtree(p->left, w, l);

    else if (cond > 0)
        p->right = addtree(p->right, w, l);


    return p;
}


/* strup: make a duplicate of s */
char *strdup(char *s)
{
    char *p;

    p = (char *) malloc(sizeof(strlen(s)+1));   /* +1 is for '\0' */

    if (p != NULL)
        strcpy(p, s);

    return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    int i;

    if (p != NULL) {
        treeprint(p->left);
        printf("%16s", p->word);

        for (i = 0; i < MAXLINES && p->lines[i]; i++)
            printf("%s%d", i == 0 ? "" : ", ", p->lines[i]);

        putchar('\n');
        treeprint(p->right);
    }
}


/* getword: get next word or character from input */
char *getword(void)
{
    static char word[100];
    int c, lim = 100;
    char *w = word;

    while (isspace(c = getch()) && c != '\n')
        ;

    if (c != EOF)
        *w++ = tolower(c);
    if (isalpha(c)) {
        for ( ; --lim > 1; w++)
            if (!isalnum(*w = tolower(getch())) && *w != '_') {
                ungetch(*w);
                break;
            }
    }

    *w = '\0';

    if (c == EOF)
        return NULL;
    else
        return word;
}
