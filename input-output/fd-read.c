#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_SIZE 4096

int main(int argc, char* argv[])
{
    int fd;
    int max_read;
    off_t filesize;
    struct stat fileinfo;
    char rbuf[MAX_SIZE] = {0};

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }

    /* open the file in read-only mode and get file size */
    if((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("cannot open file for reading.");
        return 1;
    }

    fstat(fd, &fileinfo);
    filesize = fileinfo.st_size;
    if(filesize >= MAX_SIZE)
    {
        max_read = MAX_SIZE - 1;
    }
    else
    {
        max_read = filesize;
    }

    /* read content and print it */
    if((read(fd, rbuf, max_read)) == -1)
    {
        perror("cannot read file.");
        return 1;
    }

    printf("%s\n", rbuf);
    return 0;
}