#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100
#define NUM_THREADS 4
#define NUM_FILES 8
struct job {
	/* Link field for linked list.*/
	struct job* next;

	/* Other fields describing work to be done... */
	const char* filename;
	int reverse;
};

typedef struct job job;
/* A linked list of pending jobs.*/
job* job_queue;

/* A mutex protecting job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* A semaphore counting the number of jobs in the queue.*/
sem_t job_queue_count;
/* Perform one-time initialization of the job queue.*/

void initialize_job_queue ();
void create_files(int n);
job* create_job(const char *filename, int reverse);
void enqueue_job (const char *filename, int reverse);
void process_job(job* next_job);
void merge(int* a, int low, int mid, int high);
void merge_sort(int *a, int low, int high);
void* thread_function (void* arg);

int main(){
	//Add jobs to the queue
	create_files(NUM_FILES);

	pthread_t threads_id[NUM_THREADS];
	
	int i;

	enqueue_job("file1.txt", 0);
	enqueue_job("file2.txt", 1);
	enqueue_job("file3.txt", 0);
	enqueue_job("file4.txt", 1);
	enqueue_job("file5.txt", 0);
	enqueue_job("file6.txt", 1);
	enqueue_job("file7.txt", 0);
	enqueue_job("file8.txt", 1);

	for(i = 0; i < NUM_THREADS; ++i){
		pthread_create(&threads_id[i], NULL, &thread_function, NULL);
	}

	for(i = 0; i < NUM_THREADS; ++i){
		pthread_join(threads_id[i], NULL);
	}

	return 0;
}



void initialize_job_queue ()
{
	/* The queue is initially empty. */
	job_queue = NULL;
	/* Initialize the semaphore which counts jobs in the queue.
	Its initial value should be zero. */
	sem_init (&job_queue_count, 0, 0);
}


void create_files(int n){
	char filename[20] = "";
	FILE *fp = NULL;
	int i, count, j;

	for(i = 1; i <= n; ++i){
		srand(time(NULL)*(i+2));
		sprintf(filename, "file%d.txt", i);
		fp = fopen(filename, "w");
		count = rand() % TAM_MAX;
		count = count > 10 ? count : 10;
		for(j = 0; j < count-1; ++j){
			fprintf(fp, "%d\n", rand() % 1000);
		}
		fprintf(fp, "%d", rand() % 1000);
		fclose(fp);
	}
}

job* create_job(const char *filename, int reverse){
	job *new_job = malloc(sizeof(job));

	new_job->next = NULL;
	new_job->filename = filename;
	new_job->reverse = reverse;

	return new_job;
}

/* Add a new job to the front of the job queue.
*/
void enqueue_job (const char *filename, int reverse)
{
	job* new_job = create_job(filename, reverse);
	/* Set the other fields of the job struct here... */
	/* Lock the mutex on the job queue before accessing it.*/
	pthread_mutex_lock (&job_queue_mutex);
	/* Place the new job at the head of the queue. */
	new_job->next = job_queue;
	job_queue = new_job;

	/* Post to the semaphore to indicate that another job is available.
	If threads are blocked, waiting on the semaphore, one will become
	unblocked so it can process the job. */
	sem_post (&job_queue_count);

	/* Unlock the job queue mutex. */
	pthread_mutex_unlock (&job_queue_mutex);
}

void process_job(job* next_job){
	FILE *fp = fopen(next_job->filename, "r");
	int c, count = 0, i;
	int *array = NULL;

	for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') 
            count = count + 1; 

	array = (int *)malloc(sizeof(int) * count);

	rewind(fp);

	for(i = 0; i < count; ++i)
		fscanf(fp,"%d", &array[i]);

	merge_sort(array, 0, count-1);

	fclose(fp);

	fp = fopen(next_job->filename, "w");

	if(next_job->reverse){
		for(i = count-1; i >= 0; --i)
			fprintf(fp, "%d\n", array[i]);		
	}else{
		for(i = 0; i < count; ++i)
			fprintf(fp, "%d\n", array[i]);
	}

	free(array);
	fclose(fp);
}

// merge function for merging two parts 
void merge(int* a, int low, int mid, int high) 
{ 
    int* left = malloc(sizeof(int) * (mid - low + 1)); 
    int* right = malloc(sizeof(int) * (high - mid)); 
  
    // n1 is size of left part and n2 is size 
    // of right part 
    int n1 = mid - low + 1, n2 = high - mid, i, j; 
  
    // storing values in left part 
    for (i = 0; i < n1; i++) 
        left[i] = a[i + low]; 
  
    // storing values in right part 
    for (i = 0; i < n2; i++) 
        right[i] = a[i + mid + 1]; 
  
    int k = low; 
    i = j = 0; 
  
    // merge left and right in ascending order 
    while (i < n1 && j < n2) { 
        if (left[i] <= right[j]) 
            a[k++] = left[i++]; 
        else
            a[k++] = right[j++]; 
    } 
  
    // insert remaining values from left 
    while (i < n1) { 
        a[k++] = left[i++]; 
    } 
  
    // insert remaining values from right 
    while (j < n2) { 
        a[k++] = right[j++]; 
    }

    free(left);
    free(right); 
} 
  
// merge sort function 
void merge_sort(int *a, int low, int high) 
{ 
    // calculating mid point of array 
    int mid = low + (high - low) / 2; 
    if (low < high) { 
  
        // calling first half 
        merge_sort(a, low, mid); 
  
        // calling second half 
        merge_sort(a, mid + 1, high); 
  
        // merging the two halves 
        merge(a, low, mid, high); 
    } 
}

/* Process queued jobs until the queue is empty.*/
void* thread_function (void* arg)
{
	while (1) {
		job* next_job;
		/* Wait on the job queue semaphore. If its value is positive,
		indicating that the queue is not empty, decrement the count by
		1. If the queue is empty, block until a new job is enqueued. */
		sem_wait (&job_queue_count);
		/* Lock the mutex on the job queue. */
		
		pthread_mutex_lock (&job_queue_mutex);
		/* Because of the semaphore, we know the queue is not empty. Get
		the next available job. */
		next_job = job_queue;
		/* Remove this job from the list. */
		job_queue = job_queue->next;
		/* Unlock the mutex on the job queue because we’re done with the
		queue for now. */
		pthread_mutex_unlock (&job_queue_mutex);
		
		/* Carry out the work. */
		process_job (next_job);
		/* Clean up. */
		free (next_job);
	}
	return NULL;
}


