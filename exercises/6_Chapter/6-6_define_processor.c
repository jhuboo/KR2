/* Implement a simple version of the #define processor, ie. no arguments
 * suitable for use with C programs based on the routines of this section
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/2021
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE    101
#define MAXLEN      200
#define BUFSIZE     1001
#define STATE_OUT   321
#define STATE_IN_NO_NAME    322
#define STATE_IN_WITH_NAME  323


/* Data Structures */
struct nlist {              /* table entry */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* defined name */
    char *defn;             /* replacement text */
};


static struct nlist *hashtab[HASHSIZE]; /* pointer of pointers to struct nlist*/
static int state = STATE_OUT;       /* initial state */
char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */


/* getch: get a possibly pushed back character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


/* hash: form hash value for string */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}


/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;      /* found */

    return NULL;            /* not found */
}


/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {      /* not found */

        np = (struct nlist *) malloc(sizeof(struct nlist));

        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else      /* already there */
        free((void *) np->defn);        /* free previous defn */

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}


/* undef: remove (name, defn) from table maintained by lookup & install */
int undef(char *name)
{
    struct nlist *np, *prev_np;

    if ((np = lookup(name)) == NULL)    /* not found */
        return 1;

    for (np = prev_np = hashtab[hash(name)]; np != NULL;
            prev_np = np, np = np->next)
        if (strcmp(name, np->name) == 0) {      /* found name */
            if (np == prev_np)      /* remove node from list */
                hashtab[hash(name)] = np->next;
            else
                prev_np->next = np->next;

            /* free memory */
            free(np->name);
            free(np->defn);
            free(np);
        }

    return 0;
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}


/* print_linked_list */
void print_linked_list(void)
{
    int i = 0;
    for ( ; i < HASHSIZE; i++)
        if (hashtab[i] != NULL) {
            struct nlist *p = hashtab[i];
            while (p != NULL) {
                printf("LABEL: %10s DEFN: %10s\n", p->name, p->defn);
                p = p->next;
            }
        }
}


/* simple implementation of the #define processor using above functions */
main()
{
    char *name, *defn;
    int len;
    char line[MAXLEN];

    while ((len = getword(line, MAXLEN)) > 0) {
        switch(state) {     /* initially OUT */
            case STATE_OUT:
                if (strcmp(line, "#define") == 0)
                    state = STATE_IN_NO_NAME;
                else {
                    struct nlist *np;
                    if ((np = lookup(line)) == NULL)
                        printf("%s", line);
                    else
                        printf("%s", np->defn);
                }
                break;
            case STATE_IN_NO_NAME:      /* Received name for defn */
                name = (char *) malloc(len);
                strcpy(name, line);
                state = STATE_IN_WITH_NAME;
                break;
            case STATE_IN_WITH_NAME:    /* Received defn for name */
                defn = (char *) malloc(len);
                strcpy(defn, line);
                if (install(name, defn) == NULL)    /* Update lookup table */
                    return -1;
                state = STATE_OUT;
                break;
        }
    }

    printf("\nLookup Table:\n");
    print_linked_list();

    return 0;
}
