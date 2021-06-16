/*
 * program that removes all comments from a C program
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

#define YES 1
#define NO  !YES

int main()
{
    /*
     * c is the current char
     * c_prev is the previous one
     * c_pprev is the on before c_prev
     */
    int c;
    int c_prev = '\0';
    int c_pprev = '\0';
    int is_comment = NO;
    int is_string = NO;
    int closing_symbol;

    while ((c = getchar()) != EOF) {

        if (!is_comment) {
            /* fix the slash if it is not a comment */
            if (!is_string && c_prev == '/' && c != '*' && c_pprev != '*')
                putchar('/');
            
            /* print the char if it is not the beginning of a comment */
            if (is_string || (c != '/' && (c != '*' || c_prev != '/')))
                putchar(c);
        }

        /* closing the comment */
        if (is_comment && c == '/' && c_prev == '*')
            is_comment = NO;

        /* beginning the comment */
        if (!is_comment && !is_string && c == '*' && c_prev == '/')
            is_comment = YES;

        /* closing the string or char, handles esc seq \' and \\' */
        if (is_string && c == closing_symbol && 
                (c_prev != '\\' || c_pprev == '\\'))
            is_string = NO;

        /* beginning the string or char */
        if (!is_string && !is_comment && 
                (c == '"' || c == '\'')) {
            is_string = YES;
            closing_symbol = c;
        }

        c_pprev = c_prev;
        c_prev = c;
    }

    return 0;
}
