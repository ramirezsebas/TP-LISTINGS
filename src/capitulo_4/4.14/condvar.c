#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int thread_flag, lista_random[TAM];
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_flag_mutex;

void do_work();
void initialize_flag ();
void* thread_function (void* thread_arg);
void set_thread_flag ();
void clear_thread_flag();

int main(){
	int i, flag_is_set;
	pthread_t thread_id;
	char option;

	initialize_flag();

	pthread_create(&thread_id, NULL, &thread_function, NULL);

	printf("Presione enter para empezar a generar listas aleatorias...\n");

	getchar();

	do{
		set_thread_flag();

		pthread_mutex_lock (&thread_flag_mutex);
		while(thread_flag)
			pthread_cond_wait(&thread_flag_cv, &thread_flag_mutex);
		pthread_mutex_unlock (&thread_flag_mutex);

		for(i = 0; i < TAM; ++i)
			printf("%d, ", lista_random[i]);

		printf("\nGenerar otra?: (s/n)\n");
		scanf("%c", &option);
		getchar();
		printf("\n");

	}while(option == 's');

	printf("\nPrograma finalizado!\n");

	return 0;
}

void do_work(){
	int i;
	for(i = 0; i < TAM; ++i)
		lista_random[i] = rand() % 100;
	clear_thread_flag();
}

void initialize_flag ()
{
	/* Initialize the mutex and condition variable.*/
	pthread_mutex_init (&thread_flag_mutex, NULL);
	pthread_cond_init (&thread_flag_cv, NULL);
	/* Initialize the flag value. */
	thread_flag = 0;
}

/* Calls do_work repeatedly while the thread flag is set; blocks if
the flag is clear. */
void* thread_function (void* thread_arg)
{
	/* Loop infinitely. */
	while (1) {
		/* Lock the mutex before accessing the flag value. */
		pthread_mutex_lock (&thread_flag_mutex);
		while (!thread_flag)
			/* The flag is clear. Wait for a signal on the condition
			variable, indicating that the flag value has changed. When the
			signal arrives and this thread unblocks, loop and check the
			flag again. */
			pthread_cond_wait (&thread_flag_cv, &thread_flag_mutex);
		/* When we’ve gotten here, we know the flag must be set. Unlock
		the mutex. */
		pthread_mutex_unlock (&thread_flag_mutex);
		/* Do some work. */
		do_work ();
	}
	return NULL;
}

/* Sets the value of the thread flag to FLAG_VALUE.*/
void set_thread_flag ()
{
	/* Lock the mutex before accessing the flag value. */
	int val = pthread_mutex_trylock (&thread_flag_mutex);
	/* Set the flag value, and then signal in case thread_function is
	blocked, waiting for the flag to become set. However,
	thread_function can’t actually check the flag until the mutex is
	unlocked. */
	thread_flag = 1;
	pthread_cond_signal (&thread_flag_cv);
	/* Unlock the mutex. */
	pthread_mutex_unlock (&thread_flag_mutex);
}

void clear_thread_flag ()
{
	/* Lock the mutex before accessing the flag value. */
	pthread_mutex_trylock (&thread_flag_mutex);
	/* Set the flag value, and then signal in case thread_function is
	blocked, waiting for the flag to become set. However,
	thread_function can’t actually check the flag until the mutex is
	unlocked. */
	thread_flag = 0;
	pthread_cond_signal (&thread_flag_cv);
	/* Unlock the mutex. */
	pthread_mutex_unlock (&thread_flag_mutex);
}
