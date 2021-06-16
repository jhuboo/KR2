#include <stdio.h>
#include "calc.h"

/* help: print a menu to help with calculations */
void help(void)
{
    printf("---Welcome to the Polish calculator---\n");
    printf("\nOperations are performed like so => a b operand c d operand\n");
    printf("+ \t addtion\n");
    printf("- \t subtraction\n");
    printf("* \t multiplication\n");
    printf("/ \t subtraction\n");
    printf("%% \t modulus\n");
    printf("^ \t exponentiation\n");
    printf("s \t sin\n");
    printf("c \t cos\n");
    printf("t \t tan\n");
    printf("e \t exp^x\n");
    printf("? \t show top of stack\n");
    printf("# \t duplicate last num\n");
    printf("~ \t swap two last nums\n");
    printf("! \t clear stack\n");
    printf("Press enter after a calculation to get results!\n\n");

}
