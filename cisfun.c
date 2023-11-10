#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	size_t n = 100;
	ssize_t byteCount;
	char *cmdline = malloc(sizeof(char) * n); 
	char prompt[] = "nsh$ ";
	while (1)
	{
		write(STDOUT_FILENO, prompt, 5);
		byteCount = getline(&cmdline, &n, stdin);
		lineparser(cmdline);
		if (byteCount == 0)
		{
			printf("End of Of file");
			exit(EXIT_SUCCESS);
		}
		else if (byteCount == -1)
		{
			exit(EXIT_SUCCESS);
		}
	}
	free(cmdline);
}
