#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct stat filestat;

    /* sanity check */
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if(stat(argv[1], &filestat) == -1) {
        fprintf(stderr, "can't read file: %s from %s\n", argv[1], strerror(errno));
        return errno;
    }

    printf("inode: %lu\n", filestat.st_ino);
    printf("size: %zd\n", filestat.st_size);
    printf("links: %lu\n", filestat.st_nlink);
}
