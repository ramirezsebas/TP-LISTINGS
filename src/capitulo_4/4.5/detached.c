#include <pthread.h>
#include <stdio.h>

struct DatosCliente{
	int id;
	char nombre[50];
	float deuda;
};

int complete = 0;

void* thread_function (void* thread_arg)
{
	/* Do work here... */
	struct DatosCliente cliente;
	FILE *cuentaPtr, *salida;
	float total = 0;

	salida = fopen("deuda_total.txt", "w");
	
	if ((cuentaPtr = fopen("../../src/capitulo_4/4.5/cliente.dat","r")) == NULL)
		printf("No se puede abrir el archivo\n");
	else
	{
		while (!feof(cuentaPtr))
		{
			fread(&cliente, sizeof(struct DatosCliente), 1, cuentaPtr);
			if (cliente.id != 0){
				total += cliente.deuda;
			}
		}
	}

	fprintf(salida, "%.2f\n", total);
	
	fclose(cuentaPtr);
	fclose(salida);

	complete = 1;

	printf("La deuda total es: %.2f\n", total);

	return NULL;
}

int main ()
{
	pthread_attr_t attr;
	pthread_t thread;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	pthread_create (&thread, &attr, &thread_function, NULL);
	pthread_attr_destroy (&attr);

	/* Do work here...*/

	struct DatosCliente cliente;
	FILE *cuentaPtr, *salida;

	salida = fopen("deudas_altas.txt", "w");
	
	if ((cuentaPtr = fopen("../../src/capitulo_4/4.5/cliente.dat","r")) == NULL)
		printf("No se puede abrir el archivo\n");
	else
	{
		while (!feof(cuentaPtr))
		{
			fread(&cliente, sizeof(struct DatosCliente), 1, cuentaPtr);
			if (cliente.id != 0){
				if(cliente.deuda > 6000.0)
					fprintf(salida, "%d; %s; %.2f\n", cliente.id,cliente.nombre, cliente.deuda);
			}
		}
	}
	fclose(cuentaPtr);
	fclose(salida);

	while(!complete);

	/* No need to join the second thread.*/

	return 0;
}
