#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;

	/* get and print self pid, then fork and check for errors */
	printf("My PID is: %d\n", getpid());

	if((pid = fork()) == -1)
	{
		perror("cannot fork process.");
		return 1;
	}		

	if(pid == 0)
	{
		/* if PID is 0, we are in the child process, from here we execute 'man ls' */
		if(execl("/usr/bin/man", "man", "ls", (char *)NULL) == -1)
		{
			perror("cannot exec");
			return 1;
		}		
	}
	else if(pid > 0)
	{
		/* in the parent process we wait for the child to exit with waitpid(). Afterward,
		 * the child exist status is written to 'status' */
		waitpid(pid, &status, 0);
		printf("Child executed with PID %d\n", pid);
		printf("Its return status was %d\n", status);
		printf("Its return status was %d\n", status);
	}
	else
	{
		fprintf(stderr, "Something went forking wrong.\n");
		return 1;		
	}
	return 0;
}
