#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicate a string to a new memory space location.
 * @str: Pointer to the string to be duplicated.
 *
 * Return: Pointer to the duplicated string, NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, length = 0;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate[i] = str[i];

	duplicate[i] = '\0';

	return (duplicate);
}
