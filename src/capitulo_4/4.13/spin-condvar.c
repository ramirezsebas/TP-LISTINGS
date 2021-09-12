#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4
#define TAM 20


int thread_flag;
pthread_mutex_t thread_flag_mutex;
int lista_random[TAM];

void do_work();
void initialize_flag ();
void* thread_function (void* thread_arg);
void set_thread_flag (int flag_value);
int get_thread_flag();

int main(){
	int i, flag_is_set;
	pthread_t thread_id;
	char option;

	initialize_flag();

	pthread_create(&thread_id, NULL, &thread_function, NULL);

	printf("Presione enter para empezar a generar listas aleatorias...\n");

	getchar();

	do{
		set_thread_flag(1);

		while(get_thread_flag());

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

void initialize_flag ()
{
	pthread_mutex_init (&thread_flag_mutex, NULL);
	thread_flag = 0;
}

void do_work(){
	int i;
	for(i = 0; i < TAM; ++i)
		lista_random[i] = rand() % 100;
	set_thread_flag(0);
}
/* Calls do_work repeatedly while the thread flag is set; otherwise
spins. */
void* thread_function (void* thread_arg){
	srand(time(NULL));
	while (1) {
		if (get_thread_flag())
			do_work ();
	}

	return NULL;
}
/* Sets the value of the thread flag to FLAG_VALUE.*/
void set_thread_flag (int flag_value)
{
	/* Protect the flag with a mutex lock. */
	pthread_mutex_lock (&thread_flag_mutex);
	thread_flag = flag_value;
	pthread_mutex_unlock (&thread_flag_mutex);
}

int get_thread_flag(){
	int flag_is_set;
	/* Protect the flag with a mutex lock. */
	pthread_mutex_lock (&thread_flag_mutex);
	flag_is_set = thread_flag;
	pthread_mutex_unlock (&thread_flag_mutex);

	return flag_is_set;
}

