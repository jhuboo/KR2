/* expand: expands shorthand notations in 's1' into equivalent complete
 *         list in 's2'.
 *         a-z      -> abc...xyz
 *         0-9      -> 012...789
 *         a-z0-9   -> abc...789
 *         Note: Handles leading or trailing '-' but not seq like a-b-c
 * created by Anvesh G. Jhuboo
 * on Feb/8/21
 */

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[10] = "0-F";
    char s2[100];

    expand(s1, s2);

    printf("Shorthand notation: %s\n", s1);
    printf("Expanded: %s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k;

    i = j = k = 0;

    for (i = 0; !isalnum(s1[i]); i++)   /* get first alnum int */
        ;

    while (s1[i]) {

        int first_ele = s1[i];
        int last_ele = s1[i+2];

        if (isalnum(first_ele) && s1[i+1] == '-' && isalnum(last_ele))
            if (last_ele > first_ele)
                for (j = first_ele; j <= last_ele ; j++)
                    s2[k++] = j;

        i += 3;  /* each seq has length 2; increment by 3 to go to next*/ 
    }

    s2[k] = '\0';
}




