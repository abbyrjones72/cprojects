#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <utime.h>
#define MAX_LENGTH 100
int main(int argc, char *argv[]) 
{
    char filename[MAX_LENGTH] = {0};
    /* sanity check */
    if(argc != 2) 
    {
        fprintf(stderr, "You must supply a filename as an argument.\n");
        return 1;
    }
    strncat(filename, argv[1], sizeof(filename)-1);
    /* update the access and modification time */
    if( utime(filename, NULL) == -1 ) 
    {
        /* if the file doesn't exist */
        if(errno == ENOENT) 
        {
            if(creat(filename, 00644) == -1) 
            {
                perror("cannot create file");
                return errno;
            }
        }
        /* if we cannot create timestamp, error */
        else 
        {
            perror("cannot update timestamp");
            return errno;
        }
    }
    return 0;
}