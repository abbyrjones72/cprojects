#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal);

int main(void)
{
	/* the setup */
	pid_t pid;
	pid = getpid();
	struct sigaction action;	/* for sigaction */
	sigset_t set;			/* signals we want to ignore */
	
	printf("Program running with PID: %d\n", pid);
	action.sa_handler = signal_handler;
	sigfillset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	
	/* the implementation */
	/* register two signal handlers, one for USR1, one for USR2 */
	
	/* the first arg is the signal we want to catch */
	/* the second arg is a struct for the new action we want to take */
	/* the third arg is for the old action, but we are not interested in that right now */
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	/* create the signal set for signals to ignore */
	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	/* block SIGINT and run an infinite loop */
	sigprocmask(SIG_BLOCK, &set, NULL);

	/* infinite loop to keep the program running */
	for(;;)
	{
		sleep(10);
	}
	sigprocmask(SIG_UNBLOCK, &set, NULL);

	return 0;
}

void signal_handler(int signal)
{
	if(signal == SIGUSR1)
	{
		printf("Received USR1 signal\n");
	}
	else if (signal == SIGUSR2)
	{
		printf("Received USR2 signal\n");
	}
}
