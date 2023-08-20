#include "main.h"
/**
 * main - main entry
 * @argc: no. of arguments
 * @argv: arguments passed
 * Return: 0
 */
int main(__attribute__ ((unused))int argc, char **argv)
{
	char *prompt = "$", *lineptr = NULL, *lineptr_copy = NULL, *token;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0, i;

	while (1)
	{
	printf("%s", prompt);
	nchars_read = getline(&lineptr, &n, stdin);
	if (nchars_read == -1)
	{
		printf("Exiting shell...\n");
		return (-1);
	}
	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr_copy == NULL)
	{
		perror("malloc failed");
		return (-1);
	}
	_strcpy(lineptr_copy, lineptr);
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim); }
	argv[i] = NULL;
	execmd(argv); }
	free(lineptr);
	free(lineptr_copy);
	return (0); }
