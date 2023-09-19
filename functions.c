#include "main.h"
/**
 * read_com - reads and tokenizes the command string
 * @str: input pointer to a string
 * Return: pointer to a string
 */
char **read_com(char *str)
{
	char **args = NULL, *tokens;
	int i = 0, len = 0;

	len = _strlen(str);
	args = malloc(sizeof(char *) * (len + 1));
	if (args == NULL)
		return (NULL);
	tokens = strtok(str, " \n ");
	while (tokens != NULL)
	{
		args[i] = tokens;
		i++;
		tokens = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return (args);
}
/**
* com_path - handles the pathing of executable programs
* @com: input a pointer to a string
* Return: 1 on success
*/
char *com_path(char *com)
{
	char *file_path = NULL, *path_cpy = NULL, *new = NULL, *token = NULL;
	struct stat storage;

	file_path = my_getenv("PATH");
	if (file_path != NULL && com != NULL)
	{
		if (stat(com, &storage) == 0)
			return (com);
		path_cpy = _strdup(file_path);
		token = strtok(path_cpy, ":");
		while (token != NULL)
		{
			new = malloc(_strlen(com) + _strlen(token) + 2);
			if (new == NULL)
			{
				perror("allocation failure");
				return (NULL);
			}
			_strcpy(new, token);
			_strcat(new, "/");
			_strcat(new, com);
			if (stat(new, &storage) == 0)
			{
				free(path_cpy);
				return (new);
			}
			else
			{
				free(new);
				token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
	}
	return (NULL);
}
/**
* pro_start - starts the processes
* @arg: input string pointer
* @filepath: full path of executable
* Return: 1 on success
*/
int pro_start(char **arg, char *filepath)
{
	pid_t pro_pid;

	pro_pid = fork();
	if (pro_pid == 0)
	{
		if (arg != NULL)
		{
			if (execve(filepath, arg, environ) == -1)
			{
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	else if (pro_pid == -1)
	{
		perror("fork failed");
		exit(2);
	}
	else
	{
		wait(NULL);
	}
	return (1);
}
/**
* first_pro_start - starts the processes
* @arg: input string pointer
* Return: 1 on success
*/
int first_pro_start(char **arg)
{
	pid_t pid;
	int state = 2;

	pid = fork();
	if (pid == 0)
	{
		execve(arg[0], arg, environ);
		perror("execution error");
		exit(2);
	}
	else if (pid < 0)
	{
		perror("fork failure");
		exit(2);
	}
	else
	{
		wait(&state);
		if (WIFEXITED(state))
			state = WEXITSTATUS(state);
		errno = state;

	}
	return (state);
}
/**
* built_in_do - checks for a built in comand and executes if the
*   the command is found
*   @arg: input pointer to a string
*   @buffer: memory to free
*   Return: 1 on success
*/
int built_in_do(char **arg, char *buffer)
{
	char *com_list[] = {"exit", "env"};

	int (*built_funcs[]) (char **arg, char *buffer) = {&my_exit, &my_env};

	int i, result = 0, com_len = 0;

	if (arg != NULL)
	{
		com_len = sizeof(com_list) / sizeof(com_list[0]);
		for (i = 0; i < com_len; i++)
		{
			if (_strcmp(arg[0], com_list[i]) == 0)
			{
				result = (*built_funcs[i])(arg, buffer);
			}
		}
	}
	return (result);
}
