#include "ls_h.h"
/**
* fun - Funtionn.
* Return:_return
*
*/

int fun()
{
	DIR *dp;
	struct dirent *dirp;

	dp = opendir(".");
	if (dp != NULL)
	{
		while ((dirp = readdir(dp)) != NULL)
		{
			if ((strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0 || (*dirp->d_name) == '.'))
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
* fun1 - Funtionn.
* @argc: argument
* @token: argument
* Return:_return
*
*/

int fun1(char **token)
{
	DIR *dp;
	struct dirent *dirp;

	dp = opendir(token[1]);
	if (token[2])
		fun2(token);

	if (dp != NULL)
	{
		while ((dirp = readdir(dp)) != NULL)
		{
			if ((strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0 || (*dirp->d_name) == '.'))
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
* fun2 - Funtionn.
* @token: argument
* Return:_return
*
*/
int fun2(char **token)
{
	DIR *dp, *pd;
	struct dirent *dirp, *dip;

	dp = opendir(token[2]);
	if (dp != NULL)
	{
		/* code */
		printf("%s:\n", token[2]);
		while ((dirp = readdir(dp)) != NULL)
		{
			if ((strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0 || (*dirp->d_name) == '.'))
			{
			}
			else
			{
				printf("%s ", dirp->d_name);
			}
		}
		printf("\n");
	}
	else
		printf("%s\n", token[2]);
	closedir(dp);


	pd = opendir(token[1]);
	if (pd != NULL)
	{
		/* code */
		printf("\n");
		printf("%s:\n", token[1]);
		while ((dip = readdir(pd)) != NULL)
		{
			if ((strcmp(dip->d_name, ".") == 0 || strcmp(dip->d_name, "..") == 0 || (*dip->d_name) == '.'))
			{
			}
			else
			{
				printf("%s ", dip->d_name);
			}
		}
		printf("\n");
	}
	else
		printf("%s\n", token[1]);
	closedir(pd);
	exit(EXIT_SUCCESS);
}

int fun3(char **token, char argc)
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 4 && argc == 3)
	{
		dp = opendir(token[1]);
	}	
	if(argc != 3 && argc == 2)
	{
		dp = opendir(".");
	}
	
	if (dp != NULL)
	{
		while ((dirp = readdir(dp)) != NULL)
		{
			if ((strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0 || (*dirp->d_name) == '.'))
			{
			}
			else
			{
				printf("%s\n", dirp->d_name);
			}
		}
	}
	closedir(dp);
	exit(EXIT_SUCCESS);
}


int fun4(char **token, char argc)
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 4 && argc == 3)
	{
		dp = opendir(token[2]);
	}
	if (dp != NULL)
	{
		while ((dirp = readdir(dp)) != NULL)
		{
			printf("%s ", dirp->d_name);
		}
		printf("\n");
	}
	closedir(dp);
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
		printf("%s\n", token[1]);
		break;
	}
	exit(EXIT_FAILURE);
}
