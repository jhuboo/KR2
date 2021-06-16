/* Calloc: return n objects of size 'size' with storage initialized to zero
 *
 * created by Anvesh G. Jhuboo
 * on Feb/22/2021
 */

#include "syscall.h"

/* calloc: allocate n objects of size size */
void *calloc(unsigned n, unsigned size)
{
    unsigned i, nb;
    char *p, *q;

    nb = n = size;
    if ((p = q = malloc(nb)) != NULL)
        for (i = 0; i < nb; i++)
            *p++ = 0;

    return q;
}
