#include "shell.h"

/**
 * main_shell_c - entry point
 * @argc_rd: arg count
 * @agrv_rd: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main_shell_c(__attribute__((unused)) int argc_rd, char **agrv_rd)
{
	info_t info[] = { INFO_INIT };

	hsh(info, agrv_rd);
	return (EXIT_SUCCESS);
}