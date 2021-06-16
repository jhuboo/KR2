#define NUMBER '0'  /* signal that a number was found */

/* stack.c */
void push(double);
double pop(void);
void show_top(void);
void duplicate(void);
void swap_items(void);
void clear_stack(void);
/* getop.c */
int getop(char []);
/* getch.c */
int getch(void);
void ungetch(int);
/* help.c */
void help(void);
