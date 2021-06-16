/* expr: evaluates reverse Polish expression where each operator
 *       or operand is a separate argument
 *       ~> expr 2 3 4 + *
 *       2 * (3 + 4)
 * created by Anvesh G. Jhuboo
 * on Feb/14/21
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXARGV 100     /* max arguments to argv */
char stack[MAXARGV];  /* used as a buffer for argv as seen */
int stack_height = 0; 

void panic(const char *msg);
void push(double value);
double pop(void);

/* expr program */
int main(int argc, char *argv[])
{
    /* maintain a buffer
     * check if val isdigit, if so push on buff
     * else if val is operator, pop two last values + apply opeartor on them
     * return new value to buffer
     * if reached end of argv, return value from buffer
     */
    int i;
    double value;

    for (i = 1; i < argc; i++) {
        switch (*argv[i]) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                value = pop();
                push(pop() - value);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                value = pop();
                push(pop() / value);
                break;
            default:
                panic("Unknown operator");
                break;
        }
    }

    printf("%g\n", pop());

    return 0;
}


void panic(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}


void push(double value)
{
    if (stack_height == MAXARGV)
        panic("stack is too high");
    
    stack[stack_height++] = value;
}

double pop(void)
{
    if (stack_height == 0)
        panic("stack is empty");
    
    return stack[--stack_height];
}
