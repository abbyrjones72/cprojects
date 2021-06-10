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

    /* open file with write mode */
    if((fp = fopen(argv[1], "w")) == NULL)
    {
        perror("cannot open file in write-mode.");
        return 1;
    }

    /* iterate over each line */
    while(fgets(linebuf, sizeof(linebuf), stdin) != NULL)
    {
        fprintf(fp, "%s", linebuf);
    }
    fclose(fp);
    return 0;
}