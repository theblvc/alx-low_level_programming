#include "main.h"

/**
 * leet - Encodes into 1337speak.
 * @n: The input string.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *n)
{
	int i, j;
	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (n[i] == s1[j])
			{
				n[i] = s2[j];
				break;
			}
		}
	}

	return (n);
}
