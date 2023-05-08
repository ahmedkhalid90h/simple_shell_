#include "shell.h"

/**
 * sigint_Handler - blocks ctrl-C
 * @signal_number: the signal number
 *
 * Return: void
 */
void sigint_Handler(__attribute__((unused))int signal_number)
{
	puts("\n");  // _puts_str /* up */
	puts("$ ");  // _puts_str /* up */
	putchar(BUF_FLUSH);  // _putchar /* up */
}