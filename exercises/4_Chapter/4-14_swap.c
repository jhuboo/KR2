#include <stdio.h>

/* swap(t,x,y): interchanges two args x & y of type t */
#define swap(t, x, y) \
{ \
    t temp;     /* create a temp var of type t */ \
    temp = x;   \
    x = y;      \
    y = temp;   \
}


int main()
{
    int x, y;

    x = 30;
    y = 'c';

    printf("x = %d\ny = %d\n", x, y);
    swap(int, x, y);

    printf("After swap\n");
    printf("x = %d\ny = %d\n", x, y);

    return 0;
}
