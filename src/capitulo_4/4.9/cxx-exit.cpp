#include <pthread.h>
#include <iostream>

#define MAX 5

//Funcion innecesaria para este ejemplo
//extern bool should_exit_thread_immediately ();

class ThreadExitException
{
public:
  /* Create an exception signalling thread exit with RETURN_VALUE.  */
  ThreadExitException (void* return_value)
    : thread_return_value_ (return_value)
  {
  }

  /* Actually exit the thread, using the return value provided in the
     constructor.  */
  void* DoThreadExit ()
  {
    pthread_exit (thread_return_value_);
  }

private:
  /* The return value that will be used when exiting the thread.  */
  void* thread_return_value_;
};

//Trabajo a realizar
int fact(int n){
  int i;
  int factorial=1;
  for(i=1;i<=n;i++)
    factorial = factorial * i;
  return factorial;
}


void do_some_work ()
{
  int k = 1;
  while (1) {
    /* Do some useful things here...  */

    if (k++ == MAX)
      throw ThreadExitException (/* thread's return value = */ NULL);
  }
}

void* thread_function (void*)
{
  try {
    do_some_work ();
  }
  catch (ThreadExitException ex) {
    /* Some function indicated that we should exit the thread.  */
    ex.DoThreadExit ();
  }
  return NULL;
}

int main(){
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, &thread_function, NULL);
	pthread_join(thread_id, NULL);
	return 0;
}
