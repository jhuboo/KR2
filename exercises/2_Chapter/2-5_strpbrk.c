/*
 * any: return the first location in the string s1 where any of the chars
 *      of the string s2 occurs, of -1 if s1 contains no chars from s2
 * std lib function 'strprk' does same job but returns pointer to location
 *
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

int any(const char s1[], const char s2[]);

int main()
{
    int found;

    found = any("hello world", "asizzy101saw");

    printf("First matching location: %d\n", found);

    return 0;
}


int any(const char s1[], const char s2[])
{
    int i, j;
    int not_found = -1;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    }

    return not_found;
}
