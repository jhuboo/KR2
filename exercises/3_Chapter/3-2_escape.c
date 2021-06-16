/* escape: copies string 's' to 't' while converting newlines and tabs
 *         to \n and \t
 * created by Anvesh G. Jhuboo
 * on Feb/8/21
 */

#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0' || t[j] != '\0'; i++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

int main()
{
    char text1[50] = "Hello\t world\nGood Morning\t\nAnvesh G. Jhuboo\n";
    char text2[50];

    printf("Original: \n%s\n", text1);
    escape(text1, text2);
    printf("Escaped text: \n%s\n", text2);

    return 0;
}
