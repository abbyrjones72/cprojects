#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	printf("My PID is %d\n", getpid());

	/* check for errors */
	if((pid = fork()) == -1)
	{
		perror("cannot fork process.");
		return 1;
	}

	if(pid == 0)
	{
		/* we are in the child process */
		printf("Current process: child.\n");
		exit(0);

	}
	
	/* this was wrong in the book. he did not include 'if(pid > 0)' which means
	 * none of the code below exit(0) would have ever run because any process !0
	 * would always trip the else condition of "something went wrong"
	 */

	if(pid > 0)
	{
		printf("Current process: parent.");
		printf("Current child process PID: %d\n", pid);
		sleep(120);
	}
	else
	{
		fprintf(stderr, "Something went wrong forking the process.\n");
		return 1;
	}
	
	return 0;
}
