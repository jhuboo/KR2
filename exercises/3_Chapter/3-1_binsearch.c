/*
 * binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
 * binsearch2: find x in v[0] <= v[1] <= ... <= v[n-1] using one test only
 * main: time both above functions and return results
 * created by Anvesh G. Jhuboo
 * on Feb/7/21
 */

#include <stdio.h>
#include <time.h>

#define MAX_ELEMENT 20000


int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if ( x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }

    return -1;  /* no match */
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high && x != v[mid = (low+high) / 2])
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

    return (x == v[mid]) ? mid : -1;
}

int main()
{
    int testdata[MAX_ELEMENT];
    int index;                  /* index to search for */
    int n = -1;                 /* Element to search for */
    int i;
    clock_t time_taken;         /* for binsearch1 */
    clock_t time_taken2;        /* for binsearch2 */

    /* Initialize test data */
    for (i = 0; i < MAX_ELEMENT; ++i)
        testdata[i] = i;

    /* Output approx of time taken for 100,000 iterations of binsearch */
    for (i = 0, time_taken = clock(); i < 100000; ++i)
        index = binsearch(n, testdata, MAX_ELEMENT);
    time_taken = clock() - time_taken;


    /* Output approx of time taken for 100,000 iterations of binsearch2 */
    for (i = 0, time_taken2 = clock(); i < 100000; ++i)
        index = binsearch2(n, testdata, MAX_ELEMENT);
    time_taken2 = clock() - time_taken2;

    /* Print the results */
    printf("binsearch1 tooks %lu clocks (%lu seconds)\n",
            (unsigned long)time_taken,
            (unsigned long)time_taken / CLOCKS_PER_SEC);

    printf("binsearch2 tooks %lu clocks (%lu seconds)\n",
            (unsigned long)time_taken2,
            (unsigned long)time_taken2 / CLOCKS_PER_SEC);

    return 0;
}
