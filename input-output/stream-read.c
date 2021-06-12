#include <stdio.h>

#define _1MB 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char linebuf[_1MB];

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("cannot read from file.");
        return 1;
    }

    /* sizeof is not a function and can be used like this */
    while(fgets(linebuf, sizeof linebuf, fp) != NULL)
    {
        printf("%s", linebuf);
    }

    fclose(fp);
    return 0;
}