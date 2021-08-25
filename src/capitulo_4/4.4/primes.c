#include <pthread.h>
#include <stdio.h>

/* Compute successive prime numbers (very inefficiently). Return the
Nth prime number, where N is the value pointed to by *ARG. */

void* compute_prime (void* arg)
{
	int candidate = 2;
	int n = *((int*) arg);
	while (1) {
		int factor;
		int is_prime = 1;
		/* Test primality by successive division. */
		for (factor = 2; factor < candidate; ++factor)
			if (candidate % factor == 0) {
				is_prime = 0;
				break;
			}
			/* Is this the prime number we’re looking for? */
		if (is_prime) {
			if (--n == 0) //retornar el numero primo deseado como el return del thread
				return (void*) candidate;
		}
		++candidate;
	}
	return NULL;
}

int main ()
{
	pthread_t thread;
	int which_prime = 100, n = 30, i;
	int prime;
	/* Start the computing thread, up to the 5,000th prime number. */
	pthread_create (&thread, NULL, &compute_prime, &which_prime);
	/* Do some other work here... */
  //Hacer otro trabajo mientras el otro hilo realiza el suyo
  //Por ejemplo calcular el fibonacci de un numero
	int fibonacci[n + 1];
  //Definicion de los caso base
	fibonacci[1] = 1;
	fibonacci[2] = 1;
  //calculo del enesimo fibonacci en este caso 100
	for(i = 3; i <= n; ++i){
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	printf("Fibonacci de %d es : %d\n", n, fibonacci[n]);

	/* Wait for the prime number thread to complete, and get the result.*/
	pthread_join (thread, (void*) &prime);
	/* Print the largest prime it computed. */
	printf("El %dth numero primo es %d.\n", which_prime, prime);
	return 0;
}
