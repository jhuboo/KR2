/* Rewrite previous functions using pointers, functions include:
 * getline2
 * atoi
 * itoa
 * reverse
 * strindex
 * getop
 *
 * created by Anvesh G. Jhuboo
 * on Feb/10/21
 */
#include <stdio.h>
#include <ctype.h>

/* getline2: gets line into s, return length */
int getline2(char *s, int lim)
{
    char *p;
    int c;

    p = s;
    for (int i = 0; i < lim && (c = getchar()) != '\n' && c != EOF; i++)
        *p++ = c;

    if (c == '\n')
        *p++ = c;

    *p = '\0';

    return (int)(p - s);
}

/* atoi: convert s to an integer */
int atoi(char *s)
{
    int n, sign;

    while (isspace(*s))
        s++;

    sign = (*s == '+' || *s == '-') ? ((*s++ == '+') ? 1 : -1) : 1;

    for (n = 0; isdigit(*s); s++)
        n = (n * 10) + (*s - '0');

    return sign * n;
}

/* reverse: reverse string s */
void reverse(char *s)
{
    char *p;
    int temp;

    p = s;

    while (*p)
        p++;

    p--;
    while (s <= p) {
        temp = *s;
        *s = *p;
        *p = temp;
        s++;
        p--;
    }
}

/* itoa: convert integer n to string s */
char *itoa(int n, char *s)
{
    int sign;
    char *p;

    p = s;

    sign = (n < 0) ? -1 : 1;
    (sign < 0) ? n = -n : 0;

    while (n > 0) {
        *p++ = n % 10 + '0';
        n = n / 10;
    }

    (sign == -1) ? (*p++ = '-') : 0;
    *p = '\0';
    reverse(s);
    return s;
}

/* strindex: return index of character t in char s*/
int strindex(char *s, char *t)
{
    /* increment an index n
     * if what *(s+n) == *t, then return n
     */
    char *p;    /* a copy of s */

    p = s;

    while (*p != *t && *p != '\0')
        p++;

    if (*p == '\0')
        return -1;
    else
        return (int)(p - s);
}

int main()
{
    char s[32] = "Hello world";
    char t[8]  = "g";

    int i;

    i = strindex(s, t);

    printf("Strindex: %d\n", i);
    
    return 0;
}
