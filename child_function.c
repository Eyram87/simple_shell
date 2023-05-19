#include "shell.h"

/**
 * create_child - func creates process
 * @command: tokenised pointer
 * @name: name pointer
 * @env: environmental pointer
 * @count: count executed 
 *
 * Return: Nothing
 */
void create_child(char **command, char *name, char **env, int count)
{
	int id = 0;
	int sta = 0;
	int wait = 0;

	id = fork();
	if (id < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (id == 0)
	{
		execute(command, name, env, count);
		free_dp(command);
	}
	else
	{
		wait = waitpid(id, &sta, 0);
		if (wait < 0)
		{
			free_exit(command);
		}
		free_dp(command);
	}
}

/**
 * change_dir - changes current directory
 * @path: new directory
 * Return: 1 = success/ 98 = fail
 */
int change_dir(const char *path)
{
	char *bufff = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(bufff, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
