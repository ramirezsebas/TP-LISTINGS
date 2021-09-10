#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
	++sigusr1_count;
}
int main ()
{
	struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &handler;
	sigaction (SIGUSR1, &sa, NULL);
	int pid = (int) getpid();
	for (int i=0; i<10; i++)	
        kill(pid, SIGUSR1);
	printf ("SIGUSR1 was raised %d times\n", sigusr1_count);
	return 0;
}
