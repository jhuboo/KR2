/*
 * Program that checks C program for rudimentary syntax erros
 * like {}, (), [], "", '', comments, escape sequences
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

#define MAXLINE 1000        /* max input line size */
char line[MAXLINE];         /* current input line */

int getline2(void);          /* taken from K&R2 book */


int main()
{
    int len = 0, t = 0;
    int brace = 0, bracket = 0, parenthesis = 0;
    int s_quote = 1, d_quote = 1;

    while ((len = getline2()) > 0) {

        t = 0;
        while (t < len) {
            
            if (line[t] == '{')
                brace++;
            if (line[t] == '}')
                brace--;

            if (line[t] == '(')
                parenthesis++;
            if (line[t] == ')')
                parenthesis--;

            if (line[t] == '[')
                bracket++;
            if (line[t] == ']')
                bracket--;

            if (line[t] == '\'')
                s_quote *= -1;

            if (line[t] == '"')
                d_quote *= -1;

            t++;
        }
    }

    if (s_quote != 1)
        printf("Mismatching single quote\n");
    if (d_quote != 1) 
        printf("Mismatching double quote\n");
    if (brace != 0)
        printf("Mismatching curly braces\n");
    if (parenthesis != 0)
        printf("Mismatching parenthesis\n");
    if (bracket != 0)
        printf("Mismatching square brackets\n");

    if (brace == 0 && parenthesis == 0 && bracket == 0 &&
            s_quote == 1 && d_quote == 1)
        printf("Syntax appears correct!\n");

    return 0;
}

/* getline2: writes a line into extern line[] and returns its length */
int getline2(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && 
            (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}
