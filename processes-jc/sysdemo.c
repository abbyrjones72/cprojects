#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if((system("man ls")) == -1)
	{
		fprintf(stderr, "Error forking or reading the status\n");
		return 1;
	}
	return 0;
}
