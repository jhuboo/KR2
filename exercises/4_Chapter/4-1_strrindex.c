/*
 * strrindex: return the position of the rightmost occurence of t in s
 *            or -1 if there is none
 *
 * created by Anvesh G. Jhuboo
 * on Feb/8/21
 */

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);
void reverse(char s[]);

int main()
{
    char s[64] = "Hello world";
    char t[8]  = "z";

    printf("%s\n%s\n", s, t);
    printf("%d\n", strrindex(s, t));
    printf("%s\n%s\n", s, t);

    return 0;
}

/* strrindex: performs strindex in reverse! */
int strrindex(char s[], char t[])
{
    /* reverse s & t,  perform strindex, without the middle r */
    reverse(s);
    reverse(t);

    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;   /* found */
    }

    /* put them back in the correct order */
    reverse(s);
    reverse(t);
    
    return -1;  /* not found */
}

/* reverse: reverses the characters of s in place */
void reverse(char s[])
{
    int i, j, tmp;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
