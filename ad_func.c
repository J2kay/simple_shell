#include "main.h"
/**
 * my_getenv - prints the environment variable
 * @name: name of environment variable
 * Return: 1 on success
 */
char *my_getenv(const char *name)
{
	const char *store;
	int i;
	ssize_t namelen;


	namelen = strlen(name);
	if (name == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, namelen) == 0)
		{
			store = strchr(environ[i], '=');
			if (store)
				return ((char *)(store + 1));
		}
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
