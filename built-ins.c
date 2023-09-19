#include "main.h"
/**
 * my_exit - exits from prompt
 * Return: 0 on success
 * @arg: memory to free
 * @buffer: memory to be freed
 */
int my_exit(char **arg, char *buffer)
{
	free(arg);
	free(buffer);
	exit(0);
}
/**
 * my_env - displays the current working environment
 * @arg: input a double pointer to a string
 * @buffer: ignore buffer
 * Return: 1 on success
 */
int my_env(char  **arg, char *buffer)
{
	char **print = environ;
	size_t len;

	(void)buffer;
	if (arg)
	{
		while (*print != NULL)
		{
			len = _strlen(*print);
			write(1, *print, len);
			write(1, "\n", 1);
			print++;
		}
	}
	return (1);
}
