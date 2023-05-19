#include "shell.h"

/**
 * _strcmp - It compares two strings
 * @s1: string1
 * @s2: string2
 * Return: 1 or 0
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int xx = 0;

	while (s1[xx])
	{
		if (s1[xx] != s2[xx])
			return (0);
		xx++;
	}
	return (1);
}

/**
 * _strlen - Finds length of string
 * @s: string
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcpy - func copies string to  string
 * @dest: copied string
 * @src: string to copy
 * Return: pointer to be copied
 */
char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (temp);
}

/**
 * _strcat - this funct concatenates 
 * two strings
 * @dest: string1
 * @src:  string2
 * Return: pointer to result string
 */
char *_strcat(char *dest, char *src)
{
	int xx = 0, k = 0;

	while (dest[xx] != '\0')
	{
		xx++;
	}

	while (src[k] != '\0')
	{
		dest[xx] = src[k];
		xx++;
		k++;
	}
	dest[xx] = '\0';
	return (dest);
}

/**
 * _atoi - method converts string
 * @s: input string
 * Return: integer result
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign += -1;
		if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
