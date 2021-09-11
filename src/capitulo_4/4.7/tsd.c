#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* The key used to associate a log file pointer with each thread.*/
static pthread_key_t thread_log_key;

// number of elements in array 
#define MAX 20 
  
// number of threads 
#define THREAD_MAX 4 

int a[MAX];
int part = 0;

/* Write MESSAGE to the log file for the current thread.*/
void write_to_thread_log (const char* message)
{
	FILE* thread_log = (FILE*) pthread_getspecific (thread_log_key);
	fprintf (thread_log, "%s\n", message);
}

/* Close the log file pointer THREAD_LOG.*/
void close_thread_log (void* thread_log)
{
	fclose ((FILE*) thread_log);
}

// merge function for merging two parts 
void merge(int low, int mid, int high) 
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
} 
  
// merge sort function 
void merge_sort(int low, int high) 
{ 
    // calculating mid point of array 
    int mid = low + (high - low) / 2; 
    if (low < high) { 
  
        // calling first half 
        merge_sort(low, mid); 
  
        // calling second half 
        merge_sort(mid + 1, high); 
  
        // merging the two halves 
        merge(low, mid, high); 
    } 
} 

// thread function for multi-threading 
void* merge_sort_multithreading(void* arg) 
{ 
	char thread_log_filename[20], log_message[100];
	FILE* thread_log;
	/* Generate the filename for this thread’s log file. */
	sprintf (thread_log_filename, "thread%d.log", (int) pthread_self ());
	/* Open the log file. */
	thread_log = fopen (thread_log_filename, "w");
	/* Store the file pointer in thread-specific data under thread_log_key.*/
	pthread_setspecific (thread_log_key, thread_log);
	
	write_to_thread_log ("Thread starting.");

	int old_cancel_state;

	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);

    // which part out of 4 parts 
    int thread_part = part++; 

    pthread_setcancelstate(old_cancel_state, NULL);

    sprintf (log_message, "Processing part %d of the array.", thread_part);
    write_to_thread_log (log_message);
  
    // calculating low and high 
    int low = thread_part * (MAX / 4); 
    int high = (thread_part + 1) * (MAX / 4) - 1; 

    sprintf (log_message, "The part starts at %d and ends at %d.", low, high);
    write_to_thread_log (log_message);
  
    // evaluating mid point 
    int mid = low + (high - low) / 2; 

    write_to_thread_log ("Sorting...");
    if (low < high) { 
        merge_sort(low, mid); 
        merge_sort(mid + 1, high); 
        merge(low, mid, high); 
    }
    write_to_thread_log ("Sorting finished succesfully!"); 
}

void create_random_array(){
	time_t t;

	srand((unsigned) time(&t));

	int i;
	for(i = 0; i < MAX; ++i){
		a[i] = rand() % 100;
	}

} 


int main ()
{
	int i;

	create_random_array();

	pthread_t threads[THREAD_MAX];
	/* Create a key to associate thread log file pointers in
	thread-specific data. Use close_thread_log to clean up the file
	pointers. */ 
	pthread_key_create (&thread_log_key, close_thread_log);
	/* Create threads to do the work. */
	for (i = 0; i < THREAD_MAX; ++i)
		pthread_create (&(threads[i]), NULL, merge_sort_multithreading, NULL);
	/* Wait for all threads to finish. */
	for (i = 0; i < THREAD_MAX; ++i)
		pthread_join (threads[i], NULL);

	merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1); 
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1); 
    merge(0, (MAX - 1)/2, MAX - 1); 

	for (i = 0; i < MAX; ++i)
		printf("%d\n", a[i]);

	return 0;
}