#include "shell.h"

/**
 * copy_info - copies info to create a new environment
 * @info: info
 * @value: value 
 * Return: new 
 */
char *copy_info(char *info, char *value)
{
	char *new;
	int len_info, len_value, len;

	len_info = _strlen(info);
	len_value = _strlen(value);
	len = len_info + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, info);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable

 * @info: infomantion of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env(char *info, char *value, data_shell *datash)
{
	int a;
	char *var_env, *info_env;

	for (a = 0; datash->_environ[i]; a++)
	{
		var_env = _strdup(datash->_environ[a]);
		info_env = _strtok(var_env, "=");
		if (_strcmp(info_env, info) == 0)
		{
			free(datash->_environ[a]);
			datash->_environ[a] = copy_info(info_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, a, sizeof(char *) * (a + 2));
	datash->_environ[a] = copy_info(info, value);
	datash->_environ[a + 1] = NULL;
}

/**
 * _setenv - compares environment variables names with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 * @datash: data relevant (env name)
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int a, b, c;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (a = 0; datash->_environ[a]; a++)
	{
		var_env = _strdup(datash->_environ[a]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			c = a;
		}
		free(var_env);
	}
	if (c == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (a));
	for (a = b = 0; datash->_environ[a]; a++)
	{
		if (a != c)
		{
			realloc_environ[b] = datash->_environ[a];
			b++;
		}
	}
	realloc_environ[b] = NULL;
	free(datash->_environ[c]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
