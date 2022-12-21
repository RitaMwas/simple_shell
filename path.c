#include "shell.h"
/**
 * _get_path - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
	size_t i = 0, r = 0, count = 5;
	char *path = NULL;

	for (i = 0; _strncmp(env[i], "PATH=", 5); i++)
		;
	if (env[i] == NULL)
		return (NULL);

	for (count = 5; env[i][r]; r++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (r = 5, count = 0; env[i][r]; r++, count++)
		path[count] = env[i][r];

	path[count] = '\0';
	return (path);
}
/**
 * _values_path - Separate the path in new strings.
 * @arg: Command input of user.
 * @env: Enviroment.
 * Return: Pointer to strings.
 */
int _values_path(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, len;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rela = _get_path(env);/** gets the content of "PATH="*/
	if (!path_rela)
		return (-1);
	token = strtok(path_rela, ":"); /**tokenizes the content of "PATH="*/
	len = _strlen(*arg); /**gets length of arg*/
	while (token)
	{
		value_path = _strlen(token);
		path_absol = malloc(sizeof(char) * (value_path + len + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = strcpy(path_absol, token);
		_strcat(path_absol, "/");
		_strcat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = strtok(NULL, ":");
	}
	token = '\0';
	free(path_rela);
	return (-1);
}
