#include "shell.h"

/**
 * tokening - split and create full string command
 * @s: delimiter
 * @buffer: input 
 * Return: command
 */
char **tokening(char *buffer, const char *s)
{
	char *tok = NULL, **comm = NULL;
	size_t bsize = 0;
	int xx = 0;

	if (buffer == NULL)
		return (NULL);

	bsize = _strlen(buffer);
	comm = malloc((bsize + 1) * sizeof(char *));
	if (comm == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_dp(comm);
		exit(EXIT_FAILURE);
	}

	tok = strtok(buffer, s);
	while (tok != NULL)
	{
		comm[xx] = malloc(_strlen(tok) + 1);
		if (comm[xx] == NULL)
		{
			perror("Unable to allocate buffer");
			free_dp(comm);
			return (NULL);
		}
		_strcpy(comm[xx], tok);
		tok = strtok(NULL, s);
		xx++;
	}
	comm[xx] = NULL;
	return (comm);
}

