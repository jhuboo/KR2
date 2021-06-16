/*
 * write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverse its input a line at a time.
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>
#define MAXLINE 100     /* max input string size */

void reverse(void);

int main()
{
    while (1)
        reverse();

}


/* reverse: prompts for an input string, and returns the reversed string */
void reverse(void)
{
    int c, i, j;
    char input_str[MAXLINE];
    char reversed_str[MAXLINE];

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        input_str[i] = c;

    if (c == '\n') {
        input_str[i] = c;
        ++i;
    }

    /* begin the process of reversing the string */
    for (j = 0; i >= 0; i--) {
        reversed_str[j] = input_str[i];
        ++j;
    }

    reversed_str[j] = '\0';

    printf("%s\n", reversed_str);
}
