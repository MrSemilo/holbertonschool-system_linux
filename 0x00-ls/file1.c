#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
/**
* main - is the main function that shows the content of the current directory
* Return: return
**/




int main(void)
{
	DIR *dp;
	struct dirent *dirp;

	dp = opendir(".");

	if (dp == NULL)
	{
		printf("No puedo abrir el directorio");
	}

	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(EXIT_FAILURE);
}
