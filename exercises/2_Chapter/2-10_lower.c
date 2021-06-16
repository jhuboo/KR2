/*
 * lower: convert uppercase char x to lowercase
 */
unsigned char lower(char x)
{
    return (x >= 'A' && x <= 'Z') ? x = x - 'A' + 'a' : x;
}
