#include "shell.h"

/**
 * find_commd - finds a command in PATH file path
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_commd(info_t *info)
{
    char *path = NULL;
    int counter = 0, k = 0;

    info->path = info->argv[0];
    if (info->linecount_flag == 1)
    {
        info->line_count++;
        info->linecount_flag = 0;
    }

    while (info->arg[counter])
    {
        if (!is_delimeter_char(info->arg[counter], " \t\n"))
            k++;
        counter++;
    }
    if (!k)
        return;

    path = find_path_f(info, getenv(info, "PATH="), info->argv[0]); /* up to _getenv */
    if (path)
    {
        info->path = path;
        create_child_fork(info);
    }
    else
    {
        if ((interactive_mode(info)) || getenv(info, "PATH=") /* up to _getenv */
            || info->argv[0][0] == '/' && is_cmd_(info, info->argv[0]))
            create_child_fork(info);
        else if (*(info->arg) != '\n')
        {
            info->status = 127;
            print_error(info, "not found\n");
        }
    }
}