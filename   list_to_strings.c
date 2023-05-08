#include "shell.h"

/**
 * list_to_str - returns an array of strings of the list->str
 * @head_node: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_str(list_t *head_node)
{
	list_t *node = head_node;
	size_t i = list_len(head_node), js;
	char **strs;
	char *str;

	if (!head_node || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (node)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			js = 0;
			while (js < i)
			{
				free(strs[js]);
				js++;
			}
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
		node = node->next;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
