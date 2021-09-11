#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

sig_atomic_t child_exit_status;
void clean_up_child_process (int signal_number)
{
	/* Clean up the child process. */
	int status;
	wait (&status);
  /* Store its exit status in a global variable. */
	child_exit_status = status;
}

int main ()
{
	/* Handle SIGCHLD by calling clean_up_child_process. */
	struct sigaction sigchld_action;
	memset (&sigchld_action, 0, sizeof (sigchld_action));
	sigchld_action.sa_handler = &clean_up_child_process;
	sigaction (SIGCHLD, &sigchld_action, NULL);

	pid_t pidc;

	if((pidc = fork()) == 0) {
    		printf ("Child process: %d\n", (int)getpid());
    		pid_t pidcc;

		if ((pidcc = fork()) == 0) {
			printf("Child's child process: %d\n", (int)getpid());
		} else {
      			kill((int)getpid(),SIGCHLD);
		}
	}else {
   	 	printf ("Parent process: %d\n", (int)getpid());
      		kill((int)getpid(),SIGCHLD);
	}

	return 0;
}
