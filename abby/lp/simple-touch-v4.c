#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char *argv[]) {

	char filename[PATH_MAX] = {0};
	
	/* sanity check */
	if(argc != 2) {
		fprintf(stderr, "You must provide a filename as an arguments.\n");
		return 1;
	}

	strncpy(filename, argv[1], sizeof(filename)-1);
		
	if(creat(filename, 00644) == -1) {
		if(errno == EACCES) {
			printf(stderr, "Permission denied.\n");
		} else if(errno == ENOENT) {
			printf(stderr, "Parent directory does not exist.\n");
		} else {
			printf(stderr, "Unknown error.\n");
		}
	return 0;
}
