#include <stdlib.h>

int main ()
{
  int return_value;
  //muestra el contenido del directorio root llamando a system
  return_value = system ("ls -l /");
  return return_value;
}
