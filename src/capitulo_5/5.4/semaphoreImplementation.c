#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "semun.h"

#define LOOP 5000
static int contador = 0;

static void *t1_function(void* arg);
static void *t2_function(void* arg);

int id;
int main (void)
{
  key_t key=123;
  int semid= binary_semaphore_allocation (key, IPC_CREAT | 0600);
  id= semid;
  pthread_t t1, t2;
  binary_semaphore_initialize(id);
  pthread_create (&t1, NULL, *t1_function, NULL);
  pthread_create (&t2, NULL, *t2_function, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf ("El valor del contador es: %d \n", contador);
  binary_semaphore_deallocate (id);
  return 0;
  /*El contador siempre imprime 0 gracias a la implementacion del semaforo, ya que sin el no irian por turno y se
    sumaria o restaria mas de 1 vez por y el contador no seria 0*/
}

static void *t1_function (void* arg)
{
  for (int i = 0; i< LOOP ; i++){
    binary_semaphore_wait (id);
    contador +=1;
    binary_semaphore_post (id);
  }
}

static void *t2_function (void* arg)
{
  for (int i = 0; i< LOOP ; i++){
    binary_semaphore_wait (id);
    contador -=1;
    binary_semaphore_post (id);
  }
}
