/*
 * htoi: converts a string of hex digits (including optional 0x of 0X)
 *       into its equivalent int value
 *       Allowable digits are 0-9, a-f, A-F
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>
#include <ctype.h>

unsigned long htoi(const char s[]);

int main()
{
    printf("%ld\n", htoi("0xD7AC"));
    printf("%ld\n", htoi("0x8F"));
    printf("%ld\n", htoi("0Xabcd"));
    printf("%ld\n", htoi("0x6666"));
    printf("%ld\n", htoi("0X9"));

    return 0;
}

unsigned long htoi(const char s[])
{
    unsigned long n = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        int c = tolower(s[i]);
        
        if (c == '0' && tolower(s[i+1]) == 'x')
            i++;
        else if (c >= '0' && c <= '9')
            n = 16 * n + (c - '0');
        else if (c >= 'a' && c <= 'f')
            n = 16 * n + (c - 'a' + 10);
    }

    return n;
}
