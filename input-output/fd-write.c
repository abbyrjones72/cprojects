#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd;
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s [path] [string]\n", argv[0]);
        return 1;
    }

    /* open file and create it if not exists */
    /* set in read-write mode, 0644 */
    if((fd = open(argv[1], O_CREAT | O_RDWR, 00644)) == -1)
    {
        perror("cannot open file for writing.");
        return 1;
    }

    if((write(fd, argv[2], strlen(argv[2]))) == -1)
    {
        perror("cannot write to file.");
        return 1;
    }
    return 0;
}