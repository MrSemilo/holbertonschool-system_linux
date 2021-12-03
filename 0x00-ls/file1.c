#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
/**
* main - is the main function that shows the content of the current directory
* Return: return
**/

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
	{
		dp = opendir(".");
	}
	errno = 0;
	else if((dp = opendir(argv[1])) == NULL) {
		switch (errno) {
			case EACCES: printf("Permission denied\n"); break;
			case ENOENT: printf("Directory does not exist\n"); break;
			case ENOTDIR: printf("'%s' is not a directory\n", argv[1]); break;
		}
		exit(EXIT_FAILURE);
	}
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(EXIT_FAILURE);
}
