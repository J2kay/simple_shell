#include "main.h"
/**
 * handle_comments - checks through buff and fixes comments
 * @buff: string to be fixed
 * Return: void
 */
void handle_comments(char *buff)
{
	int n;

	for (n = 0; buff[n] != '\0'; n++)
	{
		if (n > 0 && buff[n] == '#' && buff[n - 1] != ' ')
			break;
		if (buff[n] == '#')
		{
			buff[n] = '\0';
			break;
		}
	}
}
