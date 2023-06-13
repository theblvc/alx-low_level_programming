#include <stdlib.h>
#include "main.h"

/**
 * count_words - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_words(char *s)
{
	int flag = 0, count = 0;

	for (; *s != '\0'; s++)
	{
		if (*s == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
	}

	return (count);
}

/**
 * allocate_word - helper function to allocate memory for a word
 * @str: string containing the word
 * @start: starting index of the word
 * @end: ending index of the word
 *
 * Return: pointer to the allocated word, or NULL on failure
 */
char *allocate_word(char *str, int start, int end)
{
	char *word;
	int i, length = end - start;

	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		word[i] = str[start + i];
	word[length] = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success),
 *         or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *word;
	int i, k = 0, len = 0, words = 0, c = 0, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	while (str[len] != '\0')
		len++;
	words = count_words(str);
	if (words == 0)
		return (NULL);

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				word = allocate_word(str, start, end);
				if (word == NULL)
					return (NULL);
				matrix[k] = word;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}
}
