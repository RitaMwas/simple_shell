#include "shell.h"
<<<<<<< HEAD

/**
 * wordcount - counts tokens in a string for _strtok
 * @str: string to tokenize
 * @delim: delimeter between tokens
 *
 * Description: loop through string
 * If the current character is a delim, turn flag off
 * Else, turn flag on and increment the count
 *
 * Return: number of tokens
 */

int wordcount(char *str, char delim)
{
	int num = 0, i;
	int flag = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			num++;
		}
	}
	return (num);
}

/**
 * _strtok - converts a string into an array of tokens
 * @str: string to tokenize
 * @delim: delimeter between tokens
 *
 * Description: if the string is NULL, return NULL
 * Set total to number of tokens in str
 * If total is 0, return NULL
 * Allocate memory for the array of strings, check if it failed
 * Loop through string and as loop as the increment is smaller than total
 * Store current position of str in cpy
 * Go pass the characters until the delim
 * Allocate memory for the previous token, check if it failed
 * Loop through cpy (copy of the token)
 * Store each character into the array of strings words
 * Terminate the string by a null byte
 * Continue
 * Set the last string of the array to NULL, return array
 *
 * Return: pointer to the array of strings on success, or NULL on failure
 */

char **_strtok(char *str, char delim)
{
	char *cpy = NULL, **words = NULL;
	int i = 0, j = 0, len = 0, total = 0;

	if (str == 0 || *str == 0)
		return (NULL);
	total = wordcount(str, delim);
	if (total == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL)
		return (NULL);
	while (*str && i < total)
	{
		if (*str == delim)
			str++;
		else
		{
			cpy = str;
			while (*str != delim && *str)
			{
				len++;
				str++;
			}
			words[i] = malloc(sizeof(char) * (len + 1));
			if (!words[i])
				return (NULL);
			while (*cpy != delim && *cpy && *cpy != '\n')
			{
				words[i][j] = *cpy;
				cpy++;
				j++;
			}
			words[i][j] = '\0';
			i++;
			j = 0;
			len = 0;
		}
	}
	words[i] = NULL;
	return (words);
=======
/**
 * tokenize - tokenizes a stirng
 * @lineptr: what the user inputed
 * Return: a ptr to arr of ptrs
 */

char **tokenize(char *lineptr)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = strtok(lineptr, " \n\t\r");

	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	return (user_command);
>>>>>>> 2e2d0f061097512c9f1382298ad478ea9117e873
}
