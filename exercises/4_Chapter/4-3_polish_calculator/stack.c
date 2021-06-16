#include <stdio.h>
#include "calc.h"

#define MAXVAL  100     /* max depth of val stack */

static int sp = 0;             /* next free stack position */
static double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void show_top(void)
{
    if (sp > 0)
        printf("Top of stack contains: %8g\n", val[sp-1]);
    else
        printf("The stack is empty!\n");
}

void duplicate(void)
{
    double temp = pop();

    push(temp);
    push(temp);
}

void swap_items(void)
{
    double item1 = pop();
    double item2 = pop();

    push(item1);
    push(item2);
}

void clear_stack(void)
{
    /* pop only returns a value if sp > 0.
     * Setting the stack pointer to 0 will cause pop to return its error
     */
    sp = 0;
}
