#include <stdio.h>
#include <tiffio.h>
#include <string.h>
//Para instalar tiffio.h en ubuntu
// sudo apt install libtiff-dev
int main (int argc, char** argv)
{
	if(!(argc-1)){
		printf("Error al abrir el archivo.");
		return 0;
	}
	TIFF* tiff;
	char dir[70] = "../../src/capitulo_2/2.9/";
  //char dir[70] = "./";

	strcat(dir, argv[1]);
	tiff = TIFFOpen (dir, "r");
	if (tiff) {
		int dircount = 0;
		do {
		    dircount++;
	} while (TIFFReadDirectory(tiff));
		  printf("%d directorios en %s\n", dircount, argv[1]);
      TIFFClose(tiff);
  }

	return 0;
}
