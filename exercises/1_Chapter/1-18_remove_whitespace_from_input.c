/*
 * Program to remove trailing blanks and tabs from each line of input
 * Also deletes entirely blank lines
 * created by Anvesh G. Jhuboo
 * on Feb/5/21
 */

#include <stdio.h>

#define MAXLINE 1000        /* max input line length */

char line[MAXLINE + 1];
int getline2(void);

int main()
{
    int len;                    /* current line length */
    int head, tail, inn;        /* states */
    extern char line[];         /* current input line */

    while ((len = getline2()) > 0) {
        for (head = 0; line[head] == ' ' ||
                line[head] == '\t'; head++);

        for (tail = len; line[tail] == ' ' ||
                line[tail] == '\t' ||
                line[tail] == '\n' ||
                line[tail] == '\0'; tail--);

        if (tail - head >= 0) {
            for (inn = head; inn <= tail; inn++)
                putchar(line[inn]);
            putchar('\n');
            putchar('\0');
        }
    }
}

int getline2(void)
{
    extern char line[];
    int c, i;

    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n') {
        line[i] =  c;
        ++i;
    } 

    line[i] = '\0';

    return i;
}

