/*
 * print histogram of frequencies of different characters from input
 * created by Anvesh G. Jhuboo
 * on Feb/5/21
 */

#include <stdio.h>

int main() {
    
    int c;
    int ascii_chars[255];

    /* populate ascii_chars[] arr; its length is 256 */
    for (int i = 0; i < 256; i++)
        ascii_chars[i] = 0;

    while((c = getchar()) != EOF) {
        /* add it to an arr with its ASCII value */
        ++ascii_chars[c];
    }

    printf("\n\nTable of frequencies of characters in input text\n");
    printf("The text is given in its ASCII int value for simplicity\n");

    /* modify the value of i to i = 50
     * and the upper bound down from 256 to 128
     * for a more comprehensive frequency table
     */
    for (int i = 0; i < 256; i++) {
        printf("|%3d\t|%10d|\n", i, ascii_chars[i]);
    }
}
