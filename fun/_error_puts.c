#include "shell.h"

/**
 *_error_puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _error_puts(char *str)
{
	if (!str)
		return;
	for (int j = 0; str[j] != '\0'; j++)
	{
		_error_putchar(str[j]);  /* up */
	}
}