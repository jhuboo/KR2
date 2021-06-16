/* itob: convert int 'n' in a base 'b' character repr in the string 's'
 *       In particular, itob(n, s, 16) formats a hex int in s
 *       Doesn't work for greater than base 19
 *       Needs to be generalized futher
 * created by Anvesh G. Jhuboo
 * on Feb/8/21
 */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int n = 999983;     /* int n, curiosity: largest prime below 1 million */
    int b = 16;         /* base */
    char s[100];        /* string s where int 'n to base b' is stored */ 

    itob(n, s, b);

    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    /* % 16 to get a number that will do the job
     * the number will be inserted in reverse
     * need to then reverse s
     */

    int i;
    int remainder;


    do {
        remainder = n % b;

        if (remainder >= '0' && remainder <= '9')
            s[i++] = remainder + '0';
        else
            s[i++] = (remainder % 10) + 'A';

    } while (n /= b);

    s[i++] = 'x';
    s[i++] = '\\';

    s[i] = '\0';
    reverse(s);
}

/* reverse: reverses string s[] in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
