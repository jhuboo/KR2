#include <stdio.h>
#include <ctype.h>
 
#define BUFSIZE 100
 
int getch(void);
void ungetch(int c);
 
int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */
 
int main(void)
{
    int i = 0;
    char ch;
    puts("Input an integer followed by a char:");
    /* read chars until non digit or EOF */
    while ((ch = getch()) != EOF && isdigit(ch)) {
        i = 10 * i + ch - 48; /* convert ASCII into int value */
        printf("  >> Inside while body. i is %d and ch is %c\n", i, ch);
    }
     
    /* if non digit char was read, push it back into input buffer */
    if (ch != EOF) {
        printf("> Got a character (%c) that we didn't want yet because it wasn't a digit. Store it in our buffer for later\n", ch);
        ungetch(ch);
    }
 
    printf("\n\ni = %d, next char in buffer = %c\n", i, getch());
    return 0;
}
 
/* getch: get a (possibly pushed back) character */
int getch(void)
{
    printf("    >>> Inside getch(). The buffer has %d characters in it.\n", bufp);
    if (bufp == 0)
        printf("    >>> Inside getch(). Getting the character using getchar()\n");
    else
        printf("    >>> Inside getch(). Getting the character from the buffer\n");
     
    return (bufp > 0) ? buf[--bufp] : getchar();
}
 
/* ungetch: push a character back onto the input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}
