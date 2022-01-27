# ifndef _LS_H_H_
# define _LS_H_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>

void libre(int sigint);
int fun1(char **token, char argc);
int fun2(char **token);
void error(char **token);

#endif
