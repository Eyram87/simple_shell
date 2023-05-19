#include "shell.h"

/**
 * execute - Execute command
 * @command: tokenised pointer
 * @name: name shell
 * @env: shell environmental variables
 * @count: count number of executed
 *
 * Return: Noting
 */
void execute(char **command, char *name, char **env, int count)
{
	char **pat = NULL, *ful_pat = NULL;
	struct stat st;
	unsigned int ii = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		pat = _getPATH(env);
		while (pat[ii])
		{
			ful_pat = _strcat(pat[ii], command[0]);
			ii++;
			if (stat(ful_pat, &st) == 0)
			{
				if (execve(ful_pat, command, env) < 0)
				{
					perror(name);
					free_dp(pat);
					free_exit(command);
				}
				return;
			}
		}
		msg_error(name, count, command);
		free_dp(pat);
	}
}

/**
 * print_env - function prints environmental vars
 * @env: Deals environmental vars
 
 * Return: 0 or 1
 */
void print_env(char **env)
{
	size_t ii = 0, len = 0;

	while (env[ii])
	{
		len = _strlen(env[ii]);
		write(STDOUT_FILENO, env[ii], len);
		write(STDOUT_FILENO, "\n", 1);
		ii++;
	}
}

/**
 * _getPATH - func gets values in PATH
 * @env: point to environmental variables
 *
 * Return: all tokenised
 */
char **_getPATH(char **env)
{
	char *pathvalue = NULL, **pat = NULL;
	unsigned int ii = 0;

	pathvalue = strtok(env[ii], "=");
	while (env[ii])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pat = tokening(pathvalue, ":");
			return (pat);
		}
		ii++;
		pathvalue = strtok(env[ii], "=");
	}
	return (NULL);
}

/**
 * msg_error - func prints not found
 * @name: name of shell
 * @count: count cycles
 * @command: tokenised command
 * Return: Nothing
 */
void msg_error(char *name, int count, char **command)
{
	char c;

	c = count + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ":", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ":", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
