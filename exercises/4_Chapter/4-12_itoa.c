#include <stdio.h>

/* itoa: convert integer n to character string s, recursively */
void itoa(int n, char s[])
{
    static int i = 0;

    if (n < 0) {
        s[i] = '-';
        n = -n;
    }

    if (n / 10)
        itoa(n / 10, s);

    s[i++] = n % 10 + '0'; 
}


/* test itoa recursive function */
int main()
{
    int n;
    char s[8];

    n = 1234;

    itoa(n, s);

    printf("%s\n", s);

    return 0;
}

