/* Program to compare two files, printing first line where they differ
 *
 * created by Anvesh G. Jhuboo
 * on Feb/18/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100


/* comp: compare two files, printing first different line */
int comp(FILE *fp1, FILE *fp2)
{
    char l1[MAXLINE], l2[MAXLINE];
    char *lpf1, *lpf2;
    int line_count = 0;

    do {
        lpf1 = fgets(l1, MAXLINE, fp1);
        lpf2 = fgets(l2, MAXLINE, fp2);
        line_count++;

        if (lpf1 == NULL && lpf2 == NULL) {
            printf("Files match!\n");
            return 0;
        }

        if (lpf1 == NULL || lpf2 == NULL) {
            printf("<%d>: Reached EOF, files do not match\n", line_count);
            return 1;
        }

        if (strcmp(lpf1, lpf2) != 0) {
            printf("FILE 1 <%d: %s", line_count, lpf1);
            printf("FILE 2 >%d: %s", line_count, lpf2);
            return 1;
        }

    } while (strcmp(lpf1, lpf2) == 0);
    
}


/* main: comparing files */
int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    return comp(fp1, fp2);
}
