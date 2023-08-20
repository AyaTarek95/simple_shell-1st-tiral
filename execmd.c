#include "main.h"
/**
 * execmd - excute
 * @argv: arguments
 * Return: null
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;


	if (argv)
	{
		/*get the command*/
		command = argv[0];
		actual_command = get_path(command);

		/*execute the command with execve*/
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
