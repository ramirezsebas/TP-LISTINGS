#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t filebytes(char* filename);

char* read_from_file (const char* filename, size_t length)
{
	char* buffer;
	int fd;
	ssize_t bytes_read;
	/* Allocate the buffer. */
	buffer = (char*) malloc (length);
	if (buffer == NULL){
		printf("buffer returns NULL\n");
		return NULL;
	}

	/* Open the file. */
	fd = open (filename, O_RDONLY);
	if (fd == -1) {
		/* open failed. Deallocate buffer before returning. */
		printf("fd == -1\nFallo al abrir\n");
		free (buffer);
		return NULL;
	}
	/* Read the data. */
	bytes_read = read (fd, buffer, length);
	if (bytes_read != length) {
		/* read failed. Deallocate buffer and close fd before returning. */
		printf("bytes_read != length\nFallo al leer\n");
		free (buffer);
		close (fd);
		return NULL;
	}
	/* Everything’s fine. Close the file and return the buffer. */
	close (fd);
	return buffer;

}

int main(){
	char txt[50];
	//para leer cualquier tipo de archivo que se encuentre en la misma ruta que readfile.c
	printf("Introduzca nombre de archivo (default: file.txt)\n");
	scanf(" %s",txt);
	//char dir[50] = "../../src/capitulo_2/2.6/";
	char dir[50] = "./";
		strcat(dir, txt);
	char* file_txt = read_from_file( dir, filebytes(dir));
	printf("%s", file_txt);
	return 0;
}

size_t filebytes(char* filename){

	size_t fbytes = 0;
	FILE *fich;
	fich = fopen(filename,"r");

	if(fich==NULL){
		return 0;
	}else{
		fseek(fich, 0L, SEEK_END);
		fbytes = ftell(fich);
		printf("file bytes : %zu\n", fbytes);
		fclose(fich);
	}
	return fbytes;

}
