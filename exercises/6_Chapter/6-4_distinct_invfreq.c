/* Print distinct words in input sorted into decreasing order of
 * frequency occurence
 *
 * Implementation:
 * As words keep coming, compare the count
 * If incoming_word.count > parent.count && < current_child.count
 * then: incoming_word = new_child
 * make current_child new child of incoming word
 * Reallocate children of past current_child
 *
 * If incoming_word.count < parent.count (aka root)
 * incoming_word = new root
 * make parent new_child of incoming word
 *
 * If incoming_word.count > parent.count && > current_child.count
 * then: incoming_word is new_child of current_child
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/21
 */

struct tnode {              /* the tree node */
    char *word;             /* points to the text */
    int count;              /* number of occurences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
int getword(char *, int);
char *strdup(char *);


/* word frequency count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);

    treeprint(root);
    return 0;
}


/* addtree: add a word with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();   /* make a new word */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     /* repeated word */
    else if (cond < 0)  /* less than left subtree */
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);

    return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
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
