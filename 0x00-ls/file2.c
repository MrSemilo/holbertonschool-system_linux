#include "ls_h.h"
/**
* fun1 - Funtionn.
* @argc: argument
* @token: argument
* Return:_return
*
*/

int fun1(char **token, char argc)
{
	DIR *dp;
	struct dirent *dirp;

	errno = 0;
	if (argc != 2)
	{
		dp = opendir(".");
	}
	else if (token[2] != NULL)
	{
		fun2(token);
	}
	
	else
	{
		dp = opendir(token[1]);
		if (dp == NULL)
			error(token);
	}

	if (dp != NULL)
	{
		while ((dirp = readdir(dp)) != NULL)
		{
			if ((strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0
						|| (*dirp->d_name) == '.'))
			{
			}
			else
			{
				printf("%s ", dirp->d_name);
			}
		}
		printf("\n");
	}
	closedir(dp);
	exit(EXIT_SUCCESS);
}

/**
 * 
 * 
 * */
int fun2(char **token)
{
	DIR *dp, *pd;
	struct dirent *dirp, *dip;

	dp = opendir(token[2]);
	if (dp != NULL)
	{
		/* code */	
		while ((dirp = readdir(dp)) != NULL)
			{
				if ((strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0
							|| (*dirp->d_name) == '.'))
				{
				}
				else
				{
					printf("%s:\n", token[2]);
					printf("%s ", dirp->d_name);
				}
			}
			printf("\n");
	}
	else
	{
		/* code */
		printf("%s", token[2]);
	}
	
	pd = opendir(token[1]);
	if (pd != NULL)
	{
		/* code */
		while ((dip = readdir(dp)) != NULL)
		{
			if ((strcmp(dip->d_name, ".") == 0 || strcmp(dip->d_name, "..") == 0
						|| (*dip->d_name) == '.'))
			{
			}
			else
			{
				printf("%s:\n", token[1]);
				printf("%s ", dip->d_name);
			}
		}
		printf("\n");
	}
	else
	{
		/* code */
		printf("%s", token[1]);
	}
	closedir(dp);
	closedir(pd);
	exit(EXIT_SUCCESS);
}
/**
* error - Error.
* @token: argument
* Return:_return
*
*/
void error(char **token)
{
	switch (errno)
	{
	case EACCES:
		perror("Permission denied\n");
		break;
	case ENOENT:
		perror("Directory does not exist\n");
		break;
	case ENOTDIR:
		printf("'%s' is not a directory\n", token[1]);
		break;
	}
	exit(EXIT_FAILURE);
}
