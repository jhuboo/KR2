/* cat: concat f1 f2 ... fn
 * using read, write, open, close
 * remeber that they use file descriptors instead of filenames
 * therefore stdin = 0, stdout = 1, stderr = 2, and so on
 *
 * created by Anvesh G. Jhuboo
 * on Feb/20/2021
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include "syscall.h"


/* cat: concat f1 f2 .. fn */
int main(int argc, char *argv[])
{
    int fd;
    char *prog = argv[0];
    void error(char *fmt, ...);
    void filecopy(int ifd, int ofd);

    if (argc == 1)
        filecopy(0, 1);     /* no args, copy stdin to stdout */
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1)
                error("%s: cant' open %s", *prog, *argv);
            else {
                filecopy(fd, 1);
                close(fd);
            }

    return 0;

}


/* error: print an error message and die */
void error(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);

    exit(1);
}


/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n)
            error("cat: write error");
}
