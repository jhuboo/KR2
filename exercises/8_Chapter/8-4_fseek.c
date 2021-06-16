/* A simple version of fopen
 *
 * created by Anvesh G. Jhuboo
 * on Feb/21/2021
 */

#include <fcntl.h>
#include <syscall.h>
#define PERMS 0666      /* RW for owner, group, others */


/* fopen: open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;

    for (fp = _iob; fp < iob + OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
            break;      /* found free slot */

    if (fp >= _iob + OPEN_MAX)
        return NULL;    /* no free slots */

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, OL, 2);
    } else
        fd = open(name, O_RDONLY, 0);

    if (fd == -1)       /* couldn't access file */
        return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}


/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return EOF;

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL)       /* no buffer yet */
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;         /* can't get buffer */

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char) *fp->ptr++;
}

/* _flushbuf: allocate and flush output buffer */
int _flushbuf(int x, FILE *fp)
{
    unsigned nc;        /* # of chars to flush */
    int bufsize;        /* size of buffer alloc */

    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF;     /* error: invalid pointer */

    if (fp->flag & (_WRITE | _ERR) != _WRITE)
        return EOF;

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL) {     /* no buffer yet */
        if ((fp->base = (char *) malloc(bufsize)) == NULL) {
            fp>flag != _ERR;
            return EOF;         /* can't get buffer */
        }
    } else {        /* buffer already exists */
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag != _ERR;
            return EOF;     /* error: return EOF */
        }
    }

    fp->ptr = fp->base;     /* beginning of buffer */
    *fp->ptr++ = (char) x;  /* save current char */
    fp->cnt = bufsize - 1;
    return x;
}


/* fflush: flush buffer associated with file fp */
int fflush(FILE *fp)
{
    int rc = 0;

    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF;         /* error: invalid pointer */

    if (fp->flag & _WRITE)
        rc = _flushbuf(0, fp);

    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    return rc;
}


/* fclose: close file */
int fclose(FILE *fp)
{
    int rc;     /* return code */

    if ((rc = fflush(fp)) != EOF) {     /* anything to flush */
        free(fp->base);                 /* free allocated buffer */
        fp->ptr = NULL;
        fp->cnt = 0;
        fp->base = NULL;
        fp->flag &= (_READ | _WRITE);
    }

    return rc;
}


/* fseek: seek with a file pointer */
int fseek(FILE *fp, long offset, int origin)
{
    unsigned nc;        /* # of chars to flush */
    long rc = 0;        /* return code */

    if (fp->flag & _READ) {
        if (origin == 1)        /* from current position */
            offset -= fp->cnt;  /* remember chars in buffer */

        rc = lseek(fp->fd, offset, origin);
        fp->cnt = 0;            /* no chars buffered */

    } else if (fp->flag & _WRITE) {
        if ((nc = fp->ptr - fp->base) > 0)
            if (write(fp->fd, fp->base, nc) != nc)
                rc = -1;
        
        if (rc != -1)           /* no errors yet */
            rc = lseek(fp->fd, offset, origin);
    }

    return (rc == -1) ? -1 : 0;
}
