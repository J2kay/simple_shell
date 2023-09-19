#include "main.h"
/**
 * main - entry point into the program
 * @argc: argument count
 * @argv: agrument vector
 * Return: 0 always on success
 */
int main(int argc, char **argv)
{
	char  **new, *buffer = NULL, *f_path = NULL;
	int state2 = isatty(0), count = 0;
	size_t b = 0;
	ssize_t characters = 0;

	(void) argc;
	while (1)
	{
		count++;
		if (state2 == 1)
			write(1, "$ ", 2);
		characters = getline(&buffer, &b, stdin);
		if (characters == -1)
		{
			free(buffer);
			exit(0);
		}
		handle_comments(buffer);
		new = read_com(buffer);
		if (new[0] == NULL)
		{
			free(new);
			continue;
		}
		if (built_in_do(new, buffer) == 1)
			continue;
		if (access(new[0], X_OK) == 0)
			first_pro_start(new);
		else
		{
			f_path = com_path(new[0]);
			if (f_path == NULL)
				error_print(argv[0], count, new[0]);
			pro_start(new, f_path);
		}
	}
	free(buffer);
	return (0);
}
