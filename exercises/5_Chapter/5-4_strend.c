/* created by Anvesh G. jhuboo
 * on Feb/10/21
 */

#include <stdio.h>
#include <string.h>


/* strend: return 1 if string t occurs at end of string s, and 0 otherwise */
int strend(const char *s, const char *t)
{
    s += strlen(s) - strlen(t);

    while(*s && *s++ == *t++)
        ;

    return !*s; /* EOF = 0 */
}


/* test */
int main()
{
    char s[32] = "Hello world how are you today";
    char t[8]  = "today";

    int i = strend(s,t);
    
    printf("%d\n", i);

    return 0;
}
