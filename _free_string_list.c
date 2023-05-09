#include "shell.h"

/**
 * _free_string_list - frees a string of strings written
 * @str_ing: string of strings
 */
void _free_string_list(char **str_ing)
{
	char **a = str_ing;
	int i;
	if (!str_ing)
		return;
    for (i = 0; str_ing[i]; i++) {
		free(str_ing[i]);
	}
	free(a);
}