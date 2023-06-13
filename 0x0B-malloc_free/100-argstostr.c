#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenate command-line arguments into a single string
 * @ac: number of arguments
 * @av: array of argument strings
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, total_len = 0, index = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			total_len++;
	}
	total_len += ac;

	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[index] = av[i][j];
			index++;
		}

		if (str[index] == '\0')
		{
			str[index++] = '\n';
		}
	}

	return (str);
}
