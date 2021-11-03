#include "shell.h"


/**
 * main - run out process
 *
 * Return: this return 0 on sucess.
 */


int main(void)
{
	int l = 0;

	while (1)
	{
		l = shell();
		if (l == 99)
			break;
	}
	return (0);
}
