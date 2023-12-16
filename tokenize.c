#include "shell.h"

/**
 * tokenize - Splits string into words. Repeat delim are ignored.
 * @str: The input string.
 * @delim: The delimiter string.
 *
 * Return: A pointer to an array of strings. NULL on failure.
 */
char **tokenize(char *str, char *delim)
{
	int i, x, k, m, numwords;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	if (!delim)
		delim = " ";

	numwords = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], delim) && (is_delim(str[i + 1], delim) || !str[i + 1]))
			numwords++;
	}

	if (numwords == 0)
		return (NULL);

	words = malloc((numwords + 1) * sizeof(char *));
	if (!words)
		return (NULL);

	for (i = 0, x = 0; x < numwords; x++)
	{
		while (is_delim(str[i], delim))
			i++;

		k = 0;
		while (!is_delim(str[i + k], delim) && str[i + k])
			k++;

		words[x] = malloc((k + 1) * sizeof(char));
		if (!words[x])
		{
			for (k = 0; k < x; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		for (m = 0; m < k; m++)
			words[x][m] = str[i++];
		words[x][m] = '\0';
	}

	words[x] = NULL;
	return (words);
}
