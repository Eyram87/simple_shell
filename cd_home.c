#include "shell.h"

/**
 * cd_shell - change directory
 *
 * @value: relevant value
 * Return: 1 on success
 */
int cd_shell(data_shell *value)
{
	char *dir;
	int i, j, k;

	dir = value->args[1];

	if (dir != NULL)
	{
		i = _strcmp("$HOME", dir);
		j = _strcmp("~", dir);
		k = _strcmp("--", dir);
	}

	if (dir == NULL || !i || !j || !k)
	{
		cd_to_home(value);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(value);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(value);
		return (1);
	}

	cd_to(value);

	return (1);
}
