#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <linux/limits.h>

int main(int argc, char *argv[]) {
	
	char filename[PATH_MAX] = {0};
	
	/* sanity check */
	if(argc != 2) {
		fprintf(stderr, "You must provide a filename as an argument\n");
		return 1;
	}

	/* copies the filename provided from argv[1] into the filename var and sizes it
	 * to size - '\0'
	 */
	strncpy(filename, argv[1], PATH_MAX-1);
	if(creat(filename, 00644) == -1) {
		fprintf(stderr, "Can't create file %s\n", filename);
		return 1;
	}
	return 0;
}

