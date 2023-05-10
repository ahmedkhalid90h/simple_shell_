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
	_err_puts(info->filename);
	_err_puts(": ");
	print_decimal(info->line_count_, STDERR_FILENO);
	_err_puts(": ");
	_err_puts(info->argv_x[0]);
	_err_puts(": ");
	_err_puts(estr);
}
