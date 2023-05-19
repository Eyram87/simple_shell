#include "shell.h"

/**
 * free_dp - allows all memory
 * @command: allocated memory pointer
 * Return: Nothing
 */
void free_dp(char **command)
{
	size_t xx = 0;

	if (command == NULL)
		return;

	while (command[xx])
	{
		free(command[xx]);
		xx++;
	}
	
	if (command[xx] == NULL)
		free(command[xx]);
	free(command);
}

/**
 * free_exit - allows all memory
 * @command: allocated memory pointer
 * Return: viod
 */
void free_exit(char **command)
{
	size_t xx = 0;

	if (command == NULL)
		return;

	while (command[xx])
	{
		free(command[xx]);
		xx++;
	}

	if (command[xx] == NULL)
		free(command[xx]);
	free(command);
	exit(EXIT_FAILURE);
}
