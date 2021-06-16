/* Rewrite the program cat.c from Chapter 7 using read, write, open and close
 * instead of their standard libary equivalents. Perform experiments to
 * determine the relative speeds of the two versions.
 *
 * created by Anvesh G. Jhuboo
 * on Feb/20/2021
 */

#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"


/* getchar_sig: unbuffered single character input */
int getchar_sig(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


/* getchar_buf: simple buffered version */
int getchar_buf(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {   /* buffer is empty */
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}


/* cat: concatenate files */
int main(int argc, char *argv[])
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(1, buf, n);
    return 0;
}
