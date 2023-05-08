#include "shell.h"

/**
 *_puts_str - prints an input string
 *@string: the string to be printed
 *
 * Return: Nothing
 */
void _puts_str(char *string)
{
    if (!string)
        return;

    for (int inx = 0; string[inx] != '\0'; inx++) {
        putchar(string[inx]);  // _putchar /* up */
    }
}
