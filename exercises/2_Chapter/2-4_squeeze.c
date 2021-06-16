/*
 * squeeze: deletes all occurences of the character 'c' from string 's'
 * created by Anvesh G. Jhuboo
 * on Feb/6/21
 */

#include <stdio.h>

void squeeze(char s[], int c);
void squeeze2(char s1[], const char s2[]);

int main()
{
    char sentence[] = "hello world";

    squeeze2(sentence, "elr");

    printf("%s\n", sentence);

    return 0;
}

/* squeeze: squeeze deletes all 'c' from 's' */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];

    s[j] = '\0';
}

/* squeeze2: squeeze2 deletes each char in 's1' that matches any char in 's2' */
void squeeze2(char s1[], const char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                break;

        if (s2[k] == '\0')
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}
