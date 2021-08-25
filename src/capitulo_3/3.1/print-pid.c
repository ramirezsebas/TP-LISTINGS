#include <stdio.h>
#include <unistd.h>

int main()
{
  //El id del proceso
  printf("The process ID is %d\n", (int) getpid ());
  //El id del proceso padre
  printf("The parent process ID is %d\n", (int) getppid ());
  return 0;
}
