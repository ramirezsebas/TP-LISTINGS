#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "semun.h"

/* We must define union semun ourselves. */

/* Initialize a binary semaphore with a value of 1.*/

int binary_semaphore_initialize (int semid)
{
  union semun argument;
  unsigned short values[1];
  values[0] = 1;
  argument.array = values;
  return semctl (semid, 0, SETALL, argument);
}
