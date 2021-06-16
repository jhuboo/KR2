/* created by Anvesh G. Jhuboo
 * on Feb/10/21
 */

#include <stdio.h>
#include <string.h>


/* strcat: copies string t to end of s (pointer version) */
void strcat1(char *t, char *s)
{
    for ( ; *s != '\0'; s++)
        ;

    for ( ; (*s++ = *t) != '\0' ; t++)
        ;

    *s = '\0';
}


int main()
{
    char s[32] = "Hello ";
    char t[8]  = "Anvesh";

    strcat1(t, s);

    printf("%s\n", s);
    printf("%ld\n", strlen(s));
}
