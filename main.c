#include "main.h"
/**
 * main - main entry
 * @argc: no. of arguments
 * @argv: arguments passed
 * @env: env variable
 * return: 0
 */
int main(__attribute__ ((unused))int argc, char **argv)
{
	char *prompt = "$";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	char *lineptr_copy = NULL;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/*create an infinite loop*/
	while (1)
	{
	printf("%s", prompt);
	nchars_read = getline(&lineptr, &n, stdin);
	/*check if getline failed or reached EOF or user clicks ctrl+d*/
	if (nchars_read == -1)
	{
		printf("Exiting shell...\n");
		return (-1);
	}
	/*allocate space for lineptr copy*/
	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr_copy == NULL)
	{
		perror("malloc failed");
		return (-1);
	}
	
	/*copy lineptr to lineptr_copy*/
	_strcpy(lineptr_copy, lineptr);

	/*split the line into tokens*/
	/*caculate no. of tokens*/
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	
	/*allocate memory for array of tokens*/
	argv = malloc(sizeof(char *) * num_tokens);
	/*store every token in the argv array*/
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;


	/*execute the command*/
	execmd(argv);

	}


	/*free lineptr*/
	free(lineptr);
	free(lineptr_copy);
	free(argv);
	
	return (0);
}
