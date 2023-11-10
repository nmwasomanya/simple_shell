#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };

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
	char *command;
	_strcpy(command, argv[0]);
	if (execve(command, argv, env) == -1)
	{
		perror(NULL);
	}
}
