#include "main.h"
/**
 * my_getline - read lines from a file stream
 * @lineptr: pointer to a character buffer
 * @n: pointer to variable speifying size of buffer
 * @stream: pointer to a FILE stream from which input is read
 * Return: number of characters printed or -1 on failure
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	char c, *buffer = NULL;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFF_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (read(fileno(stream), &c, 1) > 0)
	{
		*lineptr[i++] = c;
		if (i >= *n - 1)
		{
			*n *= 2;
			buffer = (char *)realloc(*lineptr, *n);
			if (buffer == NULL)
			{
				perror("realloc failed");
				exit(EXIT_FAILURE);
			}
			*lineptr = buffer;
		}
		if (c == '\n')
			break;
	}
	if (c != EOF)
	{
		*lineptr[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

