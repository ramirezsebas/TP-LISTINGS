#include <stdio.h>

int f ()
{
	return 3;
}

int main ()
{
	printf("%d\n",f());
	return f ();
}
