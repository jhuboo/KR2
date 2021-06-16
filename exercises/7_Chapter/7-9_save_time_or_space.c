/* Functions like isupper can be implemented to save space or to save time
 * Explore both possibilites
 *
 * created by Anvesh G. Jhuboo
 * on Feb/20/2021
 */

/* If implemented as a function, it saves space */
int isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;   /* True */
    else 
        return 0;   /* False */
}

/* If implemented as a macro, it saves time because there is no overhead
 * of the function call but it uses more space, because the macro is
 * expanded in line every time it is invoked */
#define isupper(c)  ((c) >= 'A' && (c) <= 'Z') ? 1 : 0


/* This can lead to the potential probelm that the argument is evaluated
 * twice when increments are used
 * So it is important to be aware of that */
