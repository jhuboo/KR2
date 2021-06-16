#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP   100     /* max size of operand or operator */

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    help(); /* print the help table */
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 's':
            push(sin(pop()));
            break;
        case 'c':
            push(cos(pop()));
            break;
        case 't':
            push(tan(pop()));
            break;
        case 'e':
            push(exp(pop()));
            break;
        case '?':
            show_top();
            break;
        case '#':
            duplicate();
            break;
        case '~':
            swap_items();
            break;
        case '!':
            clear_stack();
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
