#ifndef MAIN_H
#define MAIN_H

extern char **environ;
void eval(char *argv[]);
char *lineparser(char *cmdline);
char *_strcpy(char *dest, char *src);
#endif
