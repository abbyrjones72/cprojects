#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char *argv[]) {

    char filename[PATH_MAX] = {0};

    /* sanity check */
    if(argc != 2) {
        fprintf(stderr, "You must provide a filename as an argument.\n");
        return 1;
    }
    
    strncpy(filename, argv[1], sizeof(filename)-1);
    if(creat(filename, 00644) == -1) {
        perror("Cannot create file");
        return errno;
    }
    return 0;
}