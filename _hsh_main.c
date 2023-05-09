#include "shell.h"

/**
 * _hsh_loop - main shell loop hsh
 * @info: the parameter & return info struct
 * @av_vector: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int _hsh_loop(info_t *info, char **av_vector)
{
	ssize_t r = 0;
	int builtin_ret_co = 0;

	for (;r != -1 && builtin_ret_co != -2)
	{
		clear_info(info);
		if (interactive_mode(info))
			_puts("$ ");
		_err_putchar(BUF_FLUSH);
		r = get_input_nline(info);
		if (r != -1)
		{
			set_info_initializes(info, av_vector);
			/* TODO find builtin*/
				find_cmd(info);
		}
		else if (interactive_mode(info))
			_putchar('\n');
		free_info(info, 0);
	}
	free_info(info, 1);
	if (!interactive_mode(info) && info->status)
		exit(info->status);
	if (builtin_ret_co == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret_co);
}