#include "shell.h"
#include <string.h>

/**
 * shell - this simulate the basi function of sh
 *
 * Return: 0 on sucess
*/

int shell(void)
{
	int pid1 = fork(), stlen = 0;
	char *line;
	size_t len = 0;
	char *av[] = {"\n", NULL};
	char *token;


	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
	{
		printf("#cisfun$ ");
		getline(&line, &len, stdin);
		token = strtok(line, "\n");
		if (execve(token, av, NULL) == -1)
		{

			perror("./shell");

		}

	} else
	{
		wait(NULL);

	}
}
