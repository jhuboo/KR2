/*
 * itoa: convert n to characters in s
 *       takes a third argument 'min_field_with'
 *       converted num must be padded with blanks on the left
 *       to make it wide enough
 *
 * created by Anvesh G. Jhuboo
 * on Feb/8/21
 */

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 10

void itoa(int n, char s[], int min_field_with);
void reverse(char s[]);

int main()
{
    int n = 123;
    int min_field_width = 5; /* (min_field_width + len(n)) < MAX_STR_LEN */ 
    char s[MAX_STR_LEN];

    itoa(n, s, min_field_width);

    printf("%s\n", s);

    return 0;
}


void itoa(int n, char s[], int min_field_width)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {    /* get the last digit */
        s[i++] = (n % 10) + '0';    /* add it to the string s */
    } while (n /= 10);              /* delete it */

    if (sign < 0)
        s[i++] = '-';

    /* do the left padding */
    while (i <= min_field_width) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
