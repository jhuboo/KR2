/*
 * Read a set of text lines and print the longest
 * created by Anvesh G. Jhuboo
 * inspired by K&R2
 * on Feb/5/21
 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);


/* print the longest input line */
int main()
{
    int len;            /* current line length */
    int max;            /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while((len = getline2(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)        /* there was a line */
        printf("%s", longest);

    return 0;
}


/* getline2: read a line in s, return length */
int getline2(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assumes to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
