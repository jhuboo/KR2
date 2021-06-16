/* versions of library functions
 * strncpy 
 * strncat 
 * strncmp 
 *
 * created by Anvesh G. Jhuboo
 * on Feb/10/21
 */

#include <ctype.h>

/* strncpy: copy at most n characters of string ct to s; return s
 *          Pad with '\0's if t has fewer than n characters
 */
char *strncpy1(char *s, char *ct, int n)
{
    char *ps;
    ps = s;     /* ps points to &s[0] */

    for (; n > 0 && *ct != '\0'; --n)
        *ps++ = *ct++;

    for(; n > 0; --n)
        *ps++ = '\0';

    return s;
}

/* strncat: concat at most n characters of string ct to string s
 *          terminate s with '\0', retun s
 */
char *strncat1(char *s, char *ct, int n)
{
    char *ps;
    ps = s;     /* ps points to &s[0] */

    while (isalnum(*s++)) /* s now points to the last alnum in s */
        ;

    for (; n > 0; n--)
        *ps++ = *ct++;

    *ps = '\0';
    return s;
}

/* strncmp: compare at most n characters of string cs to string ct;
 *          return <0 if cs<ct, 0 if cs==ct, >0 if cs>ct
 */
int strncmp1(const char *cs, const char *ct, int n)
{
    for (; (*cs++ == *ct++) && (n > 0); n--)
        ;

    if (n == 0 || *cs == *ct)
        return 0;
    if (*(unsigned char *)cs < *(unsigned char *)ct)    /* compare ASCII */
        return -1;
    else
        return 1;
}

/* printString: print string starting from pointer location */
void printString(const char *ptr)
{
    for ( ; *ptr != '\0'; ++ptr)
        printf("%c", *ptr);
}
