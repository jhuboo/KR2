/* Table-Lookup Package
 * Routinely used for symbol table management routines of macro processor
 * or compiler
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/2021
 */

#include <stdlib.h>
#include <string.h>
#define hashsize 101

struct nlist {              /* table entry */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* defined name */
    char *defn;             /* replacement text */
};
static struct nlist *hashtab[hashsize];


/* hash: form hash value for string */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % hashsize;
}


/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != null; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;      /* found */

    return null;            /* not found */
}


/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == null) {      /* not found */

        np = (struct nlist *) malloc(sizeof(*np));

        if (np == null || (np->name = strdup(name)) == null)
            return null;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else      /* already there */
        free((void *) np->defn);        /* free previous defn */

    if ((np->defn = strdup(defn)) == null)
        return null;
    return np;
}


/* undef: remove (name, defn) from table maintained by lookup & install */
int undef(char *name)
{
    struct nlist *np, *prev_np;

    if ((np = lookup(name)) == null)    /* not found */
        return 1;

    for (np = prev_np = hashtab[hash(name)]; np != null;
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

