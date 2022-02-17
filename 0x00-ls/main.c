#include "ls_h.h"
/**
* main - Funtionn.
* @argc: argument
* @argv: argument
* Return:_return
 **/

int main(int argc, char *argv[])
{
filtro(argc, argv);
return (0);
}


/**
* filtro - Funtionn.
* @argc: argument
* @argv: argument
* Return:_return
 **/
int filtro(int argc, char **argv)
{
if (argc != 2 && argc < 2)
{
fun();
}
if (argc != 3 && argc < 3 && (strcmp(argv[1], "-a") != 0 &&
strcmp(argv[1], "-1") != 0))
{
fun1(argv);
}
if ((strcmp(argv[1], "-1") == 0 || strcmp(argv[2], "-1") == 0))
{
fun3(argv, argc);
}
if (strcmp(argv[1], "-a") == 0)
{
fun4(argv, argc);
}
return (0);
}
