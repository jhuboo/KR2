/*
 * Count blanks, tabs, newlines
 * created by Anvesh G. Jhuboo
 * on Feb/3/21
 */

#include <stdio.h>


int main()
{
    int c;

    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    while ((c = getchar()) != EOF) {

        if (c == ' ')    /* 32 is " " */  
            blanks += 1;
        
        if (c == '\t')     /* 9 is \t */ 
            tabs += 1;
        
        if (c == '\n')    /* 10 is \n */ 
            newlines += 1;
        
    };

    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}
