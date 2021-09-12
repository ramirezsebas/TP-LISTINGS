#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

struct job {
  /* Link field for linked list.  */
  struct job* next; 

  /* Other fields describing work to be done... */
};

/* A linked list of pending jobs.  */
struct job* job_queue;

void process_job(struct job* trabajo)
{
  printf("Se hizo un trabajo");
}


/* A mutex protecting job_queue.  */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Process queued jobs until the queue is empty.  */

void* thread_function (void* arg)
{
  while (1) {
    struct job* next_job;

    /* Lock the mutex on the job queue.  */
    pthread_mutex_lock (&job_queue_mutex);
    /* Now it's safe to check if the queue is empty.  */
    if (job_queue == NULL)
      next_job = NULL;
    else {
      /* Get the next available job.  */
      next_job = job_queue;
      /* Remove this job from the list.  */
      job_queue = job_queue->next;
    }
    /* Unlock the mutex on the job queue, since we're done with the
       queue for now.  */
    pthread_mutex_unlock (&job_queue_mutex);

    /* Was the queue empty?  If so, end the thread.  */
    if (next_job == NULL)
      break;

    /* Carry out the work.  */
    process_job (next_job);
    /* Clean up.  */
    free (next_job);
  }
  return NULL;
}

int main(void){
  struct job* trabajo = (struct job*) malloc(sizeof(struct job));
  trabajo->next = NULL;
  job_queue = trabajo;
  pthread_t hilo;
  pthread_create(&hilo, NULL, &thread_function, NULL);
  pthread_join(hilo, NULL);
  return 0;
}
