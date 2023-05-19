#include "shell.h"

/**
 * main - runs the shell.
 * @ac: inputed arguments.
 * @av: array of input arguments.
 * @env: array of envirnomental variables.
 * Return: sucess or  fail
 */
int main(int ac, char **av, char **env)
{
	char *buff = NULL, **comm = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;
	int count = 0;
	(void)ac;

	while (1)
	{
		count++;
		prompt();
		signal(SIGINT, handle);
		chars_read = getline(&buff, &buf_size, stdin);
		if (chars_read == EOF)
			_EOF(buff);
		else if (*buff == '\n')
			free(buff);
		else
		{
			buff[_strlen(buff) - 1] = '\0';
			comm = tokening(buff, "\0");
			free(buff);
			if (_strcmp(comm[0], "exit") != 0)
				shell_exit(comm);
			else if (_strcmp(comm[0], "cd") != 0)
				change_dir(comm[1]);
			else
				create_child(comm, av[0], env, count);
		}
		fflush(stdin);
		buff = NULL, buf_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
