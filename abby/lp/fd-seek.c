#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define MAX_SIZE 4096

int main(int argc, char *argv[])
{
    int fd;
    int max_read;
    off_t filesize;
    struct stat fileinfo;
    char rbuf[MAX_SIZE] = {0};

    if(argc < 3 || argc > 4)
    {
        fprintf(stderr, "Usage: %s [path [from position] [bytes to read]\n", argv[0]);
        return 1;
    }

    /* open file in read-only and get the filesize */
    if((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("cannot open file for reading.");
        return 1;
    }

    /* get the files size */
    fstat(fd, &fileinfo);
    filesize = fileinfo.st_size;

    /* determine the max size we want to read
      so we don't overflow the read buffer */
    if(filesize >= MAX_SIZE)
    {
        max_read = MAX_SIZE - 1;
    }
    else if(argv[3] != NULL)
    {
        if(atoi(argv[3]) >= MAX_SIZE)
        {
            fprintf(stderr, "too large of a size specified.\n");
            return 1;
        }
        max_read = atoi(argv[3]);
    }
    else
    {
        max_read = filesize;
    }

    /* move the read position */
    lseek(fd, atoi(argv[2]), SEEK_SET);

    /* read the content and print it */
    if((read(fd, rbuf, max_read)) == -1) 
    {
        perror("cannot read from file.");
        return 1;
    }

    printf("%s\n", rbuf);
    return 0;
}