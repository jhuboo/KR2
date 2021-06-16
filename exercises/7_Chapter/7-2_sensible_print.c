/* Print arbitrary input in a sensible way.
 * Print non-graphic characters in octral or hex according to local custom,
 * and break long text lines.
 * 
 *  NEEDS DEBUGGING FOR HEX OR OCTAL FLAGS
 *
 * created by Anvesh G. Jhuboo
 * on Feb/17/2021
 */
#include <stdio.h>
#include <ctype.h>

#define OCTAL   8
#define HEX     16

/* process_args: get argv, and check if flag is for octal or hex */
void process_args(int argc, char *argv[], int *output)
{
    int i = 0;

    while (argc-- > 1) {
        if (argv[argc][0] == '-') {
            i = 1;

            while(argv[argc][i] != '\0')    /* check for -o OR -x flag */
                if (argv[argc][i] == 'o')
                    *output = OCTAL;
                else if (argv[argc][i] == 'x')
                    *output = HEX;

            i++;
        }
    }

}


/* can_print: return 1 if character c is printable, otherwise return 0 */
int can_print(int c)
{
    if (isalnum(c) || isspace(c) || isprint(c))
        return 1;        /* found */
    else
        return 0;
}


/* Program to print output in a sensible way */
int main(int argc, char *argv[])
{
    int c;
    int split = 80;     /* max line length before folding */
    int width = 0;
    int binaryrun = 0, textrun = 0;
    char *format;
    int output;

    process_args(argc, argv, &output);
    if (output == HEX) {
        format = "%02X";
        width = 4;
    } else {
        format = "%3o";
        width = 4;
    }

    while ((c = getchar()) != EOF)
        if (can_print(c)) {
            if (binaryrun > 0) {
                putchar('\n');
                binaryrun = 0;
                textrun = 0;
            }

            putchar(c);
            textrun++;

            if (c == '\n')          /* newline mechanism */
                textrun = 0;

            if (textrun == split) { /* folding mechanism */
                putchar('\n');
                textrun = 0;
            }
        } else {
            if (textrun > 0 || binaryrun + width >= split) {
                printf("\nBinary Stream: ");
                textrun = 0;
                binaryrun = 15;
            }

            printf(format, c);
            binaryrun += width;
        }

    putchar('\n');
    return 0;

}

