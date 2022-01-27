#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fb;
    char buff[255];

    fb = fopen("/tmp/test.txt", "r");
    fgets(buff, 255, fb);
    printf("%s\n", buff);
    fclose(fb);

    return(0);

}