#include "shell.h"

/**
 * create_child_fork - forks a an executable thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void create_child_fork(info_t *info)
{
	pid_t child_pid_;

	child_pid_ = fork();
	if (child_pid_ == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid_ == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}