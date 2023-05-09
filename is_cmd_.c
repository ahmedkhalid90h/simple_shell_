#include "shell.h"

/**
 * is_cmd_ - determines if a file is an executable command line true or false
 * @info: the info struct
 * @pathf: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd_(info_t *info, char *pathf)
{
	struct stat st;
	int is_executable = 0;

	(void)info;
	if (!pathf || stat(pathf, &st))
		return 0;

	while ((st.st_mode & S_IFREG) && (st.st_mode & S_IXUSR)) {
		is_executable = 1;
		break;
	}
	/* if error 
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	*/
	return is_executable;
}