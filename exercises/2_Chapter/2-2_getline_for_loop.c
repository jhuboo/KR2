/*
 * part of the getline program rewritten from a 'for loop' using && and ||
 * to one using none
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

#define LIM 80

// original
void getline1(char s[])
{
    int i, c;

    for (i = 0; i < LIM-1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
}

// modified
void getline2(char s[])
{
    int i, c;

    for (i = 0; i < LIM-1 ? (c = getchar()) != '\n' ? c != EOF : 0 : 0;
            ++i)
        s[i] = c;
}
