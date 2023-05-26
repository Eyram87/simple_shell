#include "shell.h"

/**
code that passes betty checks
* @input: input string
 * @a: index
*/
int repeated_char(char *input, int a)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, a + 1));

	return (a);
}

/**
 * @input: input string
 * @a: index
 * @end: read end char
 * Return: index of error. 0 when there are no errors
 */
int error_sep_op(char *input, int a, char end)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, a + 1, end));

	if (*input == ';')
		if (end == '|' || end == '&' || end == ';')
			return (a);

	if (*input == '|')
	{
		if (end == ';' || end == '&')
			return (a);

		if (end == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (a);
		}
	}

	if (*input == '&')
	{
		if (end == ';' || end == '|')
			return (a);

		if (end == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (a);
		}
	}

	return (error_sep_op(input + 1, a + 1, *input));
}

/**
 * @input: input string
 * @a: index
 * Return: 1 if there is an error. 0 in other case.
 */
int first_char(char *input, int *a)
{

	for (*a = 0; input[*a]; *a += 1)
	{
		if (input[*a] == ' ' || input[*a] == '\t')
			continue;

		if (input[*a] == ';' || input[*a] == '|' || input[*a] == '&')
			return (-1);

		break;
	}

	return (0);
}


/**
 * check_betty_error - intermediate function to find and print a betty error
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_betty_error(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int a = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, begin, 0);
		return (1);
	}

	a = error_sep_op(input + begin, 0, *(input + begin));
	if (a != 0)
	{
		print_syntax_error(datash, input, begin + a, 1);
		return (1);
	}

	return (0);
}

/**
 * print_betty_error - prints when a betty error is found
 * @datash: data structure
 * @input: input string
 * @a: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_betty_error(data_shell *datash, char *input, int a, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[a] == ';')
	{
		if (bool == 0)
			msg = (input[a + 1] == ';' ? ";;" : ";");
		else
			msg = (input[a - 1] == ';' ? ";;" : ";");
	}

	if (input[a] == '|')
		msg = (input[a + 1] == '|' ? "||" : "|");

	if (input[a] == '&')
		msg = (input[a + 1] == '&' ? "&&" : "&");

	msg2 = ": Betty error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}
