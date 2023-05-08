#include "shell.h"

/**
 * print_err - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_err(info_t *info, char *estr)
{
	_error_puts(info->filename);   /* up */
	_error_puts(": ");   /* up */
	print_decimal(info->line_count, STDERR_FILENO);
	_error_puts(": ");   /* up */
	_error_puts(info->argv_x[0]);   /* up */
	_error_puts(": ");   /* up */
	_error_puts(estr);   /* up */
}
