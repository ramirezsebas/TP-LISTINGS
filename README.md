# Capitulos Disponibles:
- cap 1: 1.1 - 1.3  ✓
- cap 2: 2.1 - 2.9  ✓
- cap 3: 3.1 - 3.7  ✓
- cap 4: 4.1 - 4.15 ✓
- cap 5: 5.1 - 5.12 ✓
# Listing 2.9
- Para ejecutar el listing 2.9 es necesario tener instalado una libreria de ubuntu que no viene por defecto
- sudo apt install libtiff-dev
# Trabajo Practico 1 - Lenguaje de Programacion 3

## Conforme al contenido programático de la cátedra y al contenido de libro “Advanced Linux Programing”, el Trabajo Práctico Nro. 1 se define como: “Implementar en lenguaje C/C++ los ejemplos programáticos indicados en los listings de los capítulos 1 a 5 del libro”. Para ello:

-  Los alumnos estarán habilitados a formar grupos de hasta 4 integrantes.
-  El TP deberá ser entregado en la forma de un Proyecto de Programación en C/C++ versionado
con GIT en las plataformas Github o Gitlab.
-  El desarrollo deberá estar organizado conforme a la figura de abajo:
- Se deberá identificar un directorio principal, por ejemplo “TP-LISTINGS”, el cual
contendrá los subdirectorios “src” y “bin”
- El subdirectorio “src”, contendrá a subdirectorios nombrados conforme a los capítulos
del libro y dentro de los mismos se encontrarán los archivos fuentes que implementan
los listings de cada capítulo.
- De igual forma, el subdirectorio “bin” contendrá subdirectorios nombrados de acuerdo
a los capítulos del libro y estos a su vez contendrán los programas compilados
correspondientes a los listings.

Adicionalmente, el Proyecto de Desarrollo deberá estar soportado con la utilidad GNU Make, tal que se automatice la compilación de los diferentes programas y como mínimo puedan ser soportadas las siguientes directivas:

- make all, que compila todos los programas desarrollados.
- make clean, que elimina todas la compilaciones existentes.
- make listing-X.Y, que permite compilar el ejemplo X.Y del capítulo X
    - Ej. “make listing-3.1”, que compila el listing 3.1 (print-pid.c) del capítulo 3.

### Observación importante:
Se deberá completar o complementar el código de aquellos listings que así lo requieran, de forma tal a convertirlos en programas completos, compilables y pasibles de ejecución

## Comandos
```bash
//Instalar la libreria (En Ubuntu y derivados)
sudo apt install libtiff-dev

//Compilar Todos los programas desarrolladas
make all

//Eliminar todas las compilaciones existentes.
make clean

//Compilar el ejemplo X.Y del capitulo X.
//Ej. make listing-3.1 compila el listing 3.1 (print-pid.c) del capitulo 3.
make listing-X.Y
```
