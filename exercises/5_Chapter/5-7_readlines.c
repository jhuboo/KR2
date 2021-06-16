/* Rewrite readline to store lines in an array supplied by main
 * rather than calling alloc to manage storage.
 * How much faster is the program?
 *
 * created by Anvesh G. Jhuboo
 * on Feb/14/21
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
#define MAXSTORE 10000      /* max space allocated for all lines */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *ls);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;     /* number of input lines read */
    char ls[MAXSTORE];  /* array for storing all lines */

    if ((nlines = readlines(lineptr, MAXLINES, ls)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000         /* max length of any input line */
int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *ls)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p = ls + strlen(ls);  

    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (strlen(ls) + len) > MAXSTORE)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;   /* point p to the next empty position */
        }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)      /* do nothing if array contains */
        return;             /* fewer than two elements */

    swap(v, left, (left + right)/2);

    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
