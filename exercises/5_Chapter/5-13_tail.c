/* DEBUG: This program while simple is faulty, needs to be debugged! 
 *
/* tail: print the last 10 lines of its input
 *       use flag -n to change to n lines of input
 *
 * created by Anvesh G. Jhuboo
 * on Feb/15/21
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINES    1000
#define MAXINPUT    1024
#define NUMLINES    10      /* change to alter behaviour */

int getlines(char *);
void parse_args(int, char **);

char linestr[MAXINPUT];
char *lineptr[MAXLINES];
int num_of_lines = NUMLINES;

/* tail */
int main(int argc, char *argv[])
{
    /* for input file, getlines till EOF
     * allocate an arr of pointers of size n
     * have each pointer point to a line
     * until arr[n-1] == EOF
     * return what *a[i] points to until a[n-1]
     */
    int lines;
    int ltp = 0;
    int i, c;

    if (argc > 1) { /* Parse argument strings passed to program */
        parse_args(argc, argv);
    }

    lines = getlines(linestr);  /* Get input from user */

    if (num_of_lines == 0)
        num_of_lines = 10;

    ltp = lines < num_of_lines ? lines : num_of_lines;

    printf("\n>>> Printing %d lines(s):\n", ltp);
    printf(">>> Default num of lines: %d\n", NUMLINES);

    for (i = lines; i > 0; i--) {
        while ((c = *lineptr[0]++) != '\n') {
            if (i <= ltp)
                printf("%c", c);
        }

        if (c == '\n' && i <= ltp)
            printf("\n");
    }

    return 0;
}

/* parse_args: check argv for the -n flag */
void parse_args(int argc, char **argv)
{
    char c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        c = *++argv[0];

        switch (c) {
            case 'n':
                num_of_lines = atoi(*(argv + 1));
                break;
        }
    }
}

/* getlines: get lines and store in it in an array, return length of array */
int getlines(char *buffer)
{
    int i, count = 0;
    char c;

    for (i = 0; (c = getchar()) != EOF && i < MAXINPUT; i++) {
        *buffer = c;

        if (c == '\n')
            lineptr[++count] = buffer;
    }

    *buffer++ = '\0';
    return count;
}
