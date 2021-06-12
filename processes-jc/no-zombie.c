#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/* we always want to wait for the child process to avoid creating zombie processes */

int main(void)
{
	pid_t pid;
	int status;
	printf("My PID is %d\n", getpid());

	/* fork, save the PID, and check for errors */
	if((pid = fork()) == -1)
	{
		perror("cannot fork the process.");
		return 1;		
	}

	if(pid == 0)
	{
		printf("Current location: child process.\n");
		exit(0);
	}
	if(pid > 0)
	{
		/* if pid is greater than 0, we are in the parent */
		printf("Current location: parent.\n");
		printf("Child process PID: %d\n", pid);
		waitpid(pid, &status, 0);	/* wait for the child */
		sleep(120);
	}
	else
	{
		fprintf(stderr, "Something went wrong.\n");
		return 1;
	}
		
	return 0;
}
