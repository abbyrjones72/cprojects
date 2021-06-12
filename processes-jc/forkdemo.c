#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	printf("My PID is: %d\n", getpid());

	/* fork, save the PID, and check for errors */
	if((pid = fork()) == -1)
	{
		perror("forking error!");
		return 1;
	}
	if(pid == 0)
	{
		/* if pid is 0, we are in the child process */
		printf("Hello from the child process!\n");
		sleep(120);
	}
	else if(pid > 0)
	{
		printf("Hello from the parent process. ");
		printf("My child has the PID: %d\n", pid);
		sleep(120);
	}
	else
	{
		fprintf(stderr, "Something went forking wrong, lol. Get it?");
		return 1;
	}
	return 0;
}
