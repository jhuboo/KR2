/*
 * Program that print all input lines that are longer than 80 chars
 * created by Anvesh G. Jhuboo
 * on Feb/5/21
 */

#include <stdio.h>

#define MAXLINE 10000       /* max input line size */
#define MINLEN  80          /* min length of line to be printed */

int getline2(char line[], int maxline);


int main()
{
    int len;            /* current line length */
    int min;            /* minimum length required */
    char line[MAXLINE]; /* current input line */

    min = MINLEN;
    while ((len = getline2(line, MAXLINE)) > 0) {
        if (len > min)
            printf("LINE-CONTENTS: %s\n", line);

        if (len <= min) {
            printf("Line needs to be at least 81 chars long to be printed.\n");
            printf("Try again!\n\n");
        }
    }

    return 0;
}

/* 
 * getline2: read a line in s, return length
 * Arrays, here s[], is passed by reference not value, unlike other vars 
 */
int getline2(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

