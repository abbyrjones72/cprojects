#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main( int argc, char *argv[] ) 
{
    if(argc != 2)
    {
        fprintf(stderr, "You must supply a filename as an argument.\n");
        return 1;
    }
    if( unlink(argv[1]) == -1 )
    {
        perror("cannot remove file.");
        return errno;
    }
    return 0;
}