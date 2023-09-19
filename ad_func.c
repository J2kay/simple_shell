#include "main.h"
/**
 * my_getenv - prints the environment variable
 * @name: name of environment variable
 * Return: 1 on success
 */
char *my_getenv(const char *name)
{
	char *store, *tokens;
	int i, j;

	if (name == NULL)
	{
		return (NULL);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		store = _strdup(environ[i]);
		if (store == NULL)
		{
			for (j = 0; j < i; j++)
				free(store);
			return (NULL);
		}
		tokens = strtok(store, "=");
		if (_strcmp(tokens, (char *)name) == 0)
		{
			tokens = strtok(NULL, "=");
			return (tokens);
		}
		free(store);
	}
	return (NULL);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
/**
 * _puts - prints characters
 *  @str: pointer to a string
 *  Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
