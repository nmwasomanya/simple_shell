#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *lineparser(char *cmdline)
{
	char *argv[100];
	char *str = malloc(sizeof(char) * strlen(cmdline));
	char *delim = " ";
	int i = 0;
	
	_strcpy(str, cmdline);
	argv[i] = strtok(str, delim);
	
	while (argv[i] != NULL)
		argv[++i] = strtok(NULL, delim);
	
	eval(argv);	
}

 
void eval(char *argv[])
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror(NULL);
	}
}
