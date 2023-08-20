#include "main.h"
/**
 * _strcpy - Short description, single line
 * @dest: Description of parameter x
 * @src: 2nd
 * Return: Description of the returned value
 */
char *_strcpy(char *dest, char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
        {
                dest[i] = src[i];
        }
        dest[i] = '\0';
        return (dest);
}
/**
*_strlen - Entry point
*
*Description: A C program that prints with put function
*@s: 1st
*Return: Always 0 (success)
*/
int _strlen(char *s)
{
        int len;

        for (len = 0; *s != '\0'; s++)
                ++len;

        return (len);
}
/**
 * _strcat  - Short description, single line
 * @dest: desc
 * @src: source
 * Return: return dest
 */

char *_strcat(char *dest, char *src)
{
	return (strcat(dest, src));
}
/**
 * *_strdup - copies str
 * @str: duplicated str
 * Return: pointer to copied str
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = str[i]) != '\0')
		i++;

	return (dup);
}

