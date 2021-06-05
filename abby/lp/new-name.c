#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    /* we need 3 args */
    if(argc !=3) {
        fprintf(stderr, "Usage: %s [target] [new-name]\n", argv[0]);
        return 1;
    }

    if(link(argv[1], argv[2]) == -1) {

        /* use perror to handle things like:
            -> file exists
            -> permission denied if directory !exists
        */
        perror("can't create link");
        return 1;
   }
   return 0;
}