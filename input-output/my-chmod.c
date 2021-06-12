#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void print_usage(FILE *stream, char progname[]);

int main(int argc, char *argv[])
{
    long int accessmode;

    if(argc != 3)
    {
        print_usage(stderr, argv[0]);
        return 1;
    }

    /* check for octal numbers */
    if(strspn(argv[1], "01234567\n") != strlen(argv[1]) || (strlen(argv[1]) != 3 && strlen(argv[1]) != 4))
    {
        print_usage(stderr, argv[0]);
        return 1;
    }

    /* convert to octal and set the permissions */
    accessmode = strtol(argv[1], NULL, 8);
    if(chmod(argv[2], accessmode) == -1)
    {
        perror("Can't change permissions.\n");
    }
    return 0;
}

void print_usage(FILE *stream, char progname[])
{
    fprintf(stream, "Usage: %s <numerical permissions> <path>\n", progname);
}