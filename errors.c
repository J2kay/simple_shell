#include "main.h"
/**
 * error_print - handles the error message
 * @str: name of my shell
 * @counter: command count
 * @arg: command entered
 * Return: void
 */
void error_print(char *str, int counter, char *arg)
{
	char num = counter + '0';

	_puts(str);
	_puts(": ");
	_putchar(num);
	_puts(": ");
	_puts(arg);
	_puts(": not found\n");
	exit(127);
}
