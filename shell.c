#include "shell.h"
#include <string.h>

/**
 * shell - this simulate the basi function of sh
 *
 * Return: 0 on sucess
*/

int shell(void)
{
	int pid1 = fork(), status, statuscode;
	size_t len = 0;
	char *av[] = {"\n", NULL}, *token, *line;


	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
	{
		printf("#cisfun$ ");
		getline(&line, &len, stdin);
		if (feof(stdin))
			exit(3);

		token = strtok(line, "\n");
		if (execve(token, av, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}

	} else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			statuscode = WEXITSTATUS(status);
		        if (statuscode == 3)
				return (99);
		}
	}
	return 0;
}
