/* reverse_case: convert upper case to lower case, or vice versa
 * depending on the name invoked with in argv[0]
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/21
 */

#include <stdio.h>
#include <ctype.h>


/* reverse-case */
int main(int argc, char *argv[])
{
    int c;

    printf("\n ----- Help -----\n");
    printf("\nUse 'reverse_case u' to convert to uppercase\n");
    printf("Use 'reverse_case l' to convert to lowercase\n");

    while ((c = getchar()) != EOF)
        if (tolower(*argv[1]) == 'u')
            putchar(toupper(c));
        else if (tolower(*argv[1]) == 'l')
            putchar(tolower(c));

    return 0;
}
