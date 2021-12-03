#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
/**
* main - Funtionn.
* @argc: argument
* @argv: argument
* Return:_return
*
*/
int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	errno = 0;
	if (argc != 2)
	{
		dp = opendir(".");
	}
	else
	{
		dp = opendir(argv[1]);
		errno = 0;
		if (dp == NULL)
		{
			switch (errno)
			{
				case EACCES:
					printf("Permission denied\n");
					break;
				case ENOENT:
					printf("Directory does not exist\n");
					break;
				case ENOTDIR:
					printf("'%s' is not a directory\n", argv[1]);
					break;
			}
		exit(EXIT_FAILURE);
		}
	}
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);
	exit(EXIT_SUCCESS);
}
