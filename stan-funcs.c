#include "main.h"

/**
 * *_strcpy - copies a string from one address to the other
 * @dest: input pointer
 * @src: input pointer
 * Return: character
 */

char *_strcpy(char *dest, char *src)
{
	int n = 0, length = 0, i;
	char **new;

	new = &dest;

	while (src[n] != '\0')
	{
		n++;
		length++;
	}

	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}
	dest[length] = '\0';
	return (*new);
}
/**
 * *_strcat - concatinates two strings
 * @dest: input string pointer
 * @src: input string pointer
 * Return: pointer to destination
 */

char *_strcat(char *dest, char *src)
{
	int a, b;



	for (b = 0; dest[b] != '\0'; b++)
	{
	}

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[b + a] = src[a];
	}
	return (dest);
}
/**
 * _strlen - counts the length of a string
 * @s: dereference of an array
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int n = 0;

	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}
/**
 * _strcmp - compares two strings
 * @s1: input string array
 * @s2: input string array
 * Return: 0 on success
 */


int _strcmp(char *s1, char *s2)
{
	int a = 0, b = 0;

	while (s1[a] != '\0' && s2[b] == s1[a])
	{
		a++;
		b++;
	}

	return (s1[a] - s2[b]);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string array pointer
 * Return: pointer to new array
 */

char *_strdup(char *str)
{
	int i, j, len = 0;
	char *new;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}

	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < len; j++)
	{
		new[j] = str[j];
	}
	new[len] = '\0';
	return (new);
}
