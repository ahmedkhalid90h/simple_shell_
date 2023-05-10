#include "shell.h"

/**
 *_puts_str - prints an input string STRING
 *@string: the string to be printed
 *
 * Return: Nothing
 */
void _puts_str(char *string)
{
    int inx = 0;
    if (!string)
        return;

    for (inx = 0; string[inx] != '\0'; inx++) {
        putchar(string[inx]);   /* up to _putchar */
    }
}
