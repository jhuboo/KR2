/* pattern finding program - variation of the one found in Chapter 5
 * takes input from set of named FILES, or if no files are given, from stdin
 * Should the file name be printed when a matching line is found?
 *
 * created by Anvesh G. Jhuboo
 * on Feb/18/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN  100

/* getline2: write line in string, return len */
int getline2(char *line, int max, FILE *fp)
{
    if (fgets(line, max, fp) == NULL)
        return -1;
    else
        return strlen(line);
}


/* main: return pattern if found in file */
/* usage: ~>$./pattern_find.o pattern FILE */
int main(int argc, char *argv[])
{
    int line_count;
    char *pattern;
    char line_storage[MAXLEN];
    FILE *fp;

    line_count = 0;
    pattern = argv[1];
    fp = fopen(argv[2], "r");

    while (getline2(line_storage, MAXLEN, fp) != -1) {
        line_count++;

        if (strstr(line_storage, pattern) != NULL) {
            printf("Pattern, %s, found at line:\n", pattern);
            printf("%d < %s\n", line_count, line_storage);
            exit(0);
        }
    }

    printf("Pattern not found\n");
    fclose(fp);
    exit(0);
}
