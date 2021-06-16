#include <stdio.h>
#include <string.h>


/* reverse: reverse characters of string s, recursively */
void reverse(char s[])
{
    static int i, j;

    if (s[i]) {
        int c = s[i++];
        reverse(s);
        s[j++] = c;
    }

    if (i == j) /* reset the static ints */
        i = 0, j = 0;
}


int main()
{
    char s[] = "Hello world!";

    reverse(s);

    printf("%s\n", s);

    return 0;
}
