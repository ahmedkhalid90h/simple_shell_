#include "shell.h"

/**
 * is_delimeter_char - checks if character is a delimeter line character
 * @ch: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter_char(char ch, char *delimiter)
{
    for (char* ptr = delimiter; *ptr != '\0'; ptr++) {
        if (*ptr == ch) {
            return 1;
        }
    }
    return 0;
}