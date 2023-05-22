#include "shell.h"

/**
 * prompt - func prints prompt msgs
 * Return: Nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}

/**
 * handle - function handle (Ctrl+C)
 * @signals: symbol to handle
 * Return: Nothing
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * _EOF - checks buffer
 * @buffer: input string pointer
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * shell_exit - func exits shell
 * @command: tokenised command
 * Return: Nothing
 */
void shell_exit(char **command)
{
	int error_flg = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	error_flg = _atoi(command[1]);
	free_dp(command);
	if (error_flg >= 0 && error_flg <= 255)
		exit(error_flg);
	exit(255);
}

