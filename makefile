#Definicion de variables

ROOT   := ./
#Definir las rutas del proyecto
#Para el codigo fuente, los objetos y los binarios
SOURCEDIR   := $(ROOT)src/
OBJECTDIR   := $(ROOT)obj/
BINDIR   := $(ROOT)bin/

OBJS =   capitulo1 capitulo2 capitulo3 capitulo4 capitulo5


# ubicacion del capitulo 1
cap1 = $(OBJECTDIR)capitulo_1/
srccap1 = $(SOURCEDIR)capitulo_1/
bincap1 = $(BINDIR)capitulo_1/


CAP2 := capitulo_2/

#Source del capitulo 2
C2_S = $(SOURCEDIR)$(CAP2)

#Source del objeto del capitulo 2
C2_O = $(OBJECTDIR)$(CAP2)

#Source del binario del capitulo 2
C2_B = $(BINDIR)$(CAP2)


CAP3 := capitulo_3/

#Source del capitulo 3
C3_S = $(SOURCEDIR)$(CAP3)

#Source del objeto del capitulo 3
C3_O = $(OBJECTDIR)$(CAP3)

#Source del binario del capitulo 3
C3_B = $(BINDIR)$(CAP3)



CAP4 := capitulo_4/

#Source del capitulo 4
C4_S = $(SOURCEDIR)$(CAP4)

#Source del objeto del capitulo 4
C4_O = $(OBJECTDIR)$(CAP4)

#Source del binario del capitulo 4
C4_B = $(BINDIR)$(CAP4)


CAP5 := capitulo_5/

#Source del capitulo 5
C5_S = $(SOURCEDIR)$(CAP5)

#Source del objeto del capitulo 5
C5_O = $(OBJECTDIR)$(CAP5)

#Source del binario del capitulo 5
C5_B = $(BINDIR)$(CAP5)

#Creacion de las carpetas obj, src y bin y de los subdirs
folder= $(OBJECTDIR) $(BINDIR) $(OBJECTDIR)capitulo_1 $(OBJECTDIR)capitulo_2 $(OBJECTDIR)capitulo_3 $(OBJECTDIR)capitulo_4 $(OBJECTDIR)capitulo_5 \
$(BINDIR)capitulo_1 $(BINDIR)capitulo_2 $(BINDIR)capitulo_3 $(BINDIR)capitulo_4 $(BINDIR)capitulo_5

folder1= $(OBJECTDIR) $(BINDIR) $(OBJECTDIR)capitulo_1 \
$(BINDIR)capitulo_1

folder2= $(OBJECTDIR) $(BINDIR) $(OBJECTDIR)capitulo_2 \
$(BINDIR)capitulo_2

folder3= $(OBJECTDIR) $(BINDIR) $(OBJECTDIR)capitulo_3 \
$(BINDIR)capitulo_3

folder4= $(OBJECTDIR) $(BINDIR) $(OBJECTDIR)capitulo_4 \
$(BINDIR)capitulo_4

folder5= $(OBJECTDIR) $(BINDIR) $(OBJECTDIR)capitulo_5 \
$(BINDIR)capitulo_5

#Compilado del capitulo 1

all: $(OBJS)
	@echo "\n"

capitulo1: carpeta1 $(cap1)main.o $(cap1)reciprocal.o
	@g++ $(CFLAGS) -o $(bincap1)capitulo1 $(cap1)main.o $(cap1)reciprocal.o
	@echo "Seleccionaste el Capitulo 1\n"
	@echo " - Reciprocal\n - Main\n"
	@echo "El programa se encuentra compilado en bin del capitulo 1: ./capitulo1 <numero>\n"

$(cap1)main.o: $(srccap1)1.1/main.c
	@gcc $(CFLAGS) -c $(srccap1)1.1/main.c -o $(cap1)main.o -I $(srccap1)1.3/

$(cap1)reciprocal.o: $(srccap1)1.2/reciprocal.cpp
	@g++ $(CFLAGS) -c $(srccap1)1.2/reciprocal.cpp -o $(cap1)reciprocal.o -I $(srccap1)1.3/


#Compilado del capitulo 2
capitulo2: carpeta2 arglist_out getopt_out print_out client_out temp_file_out readfile_out app_out tifftest_out
	@echo "Seleccionaste el Capitulo 2\n"
	@echo " -arglist\n -getopt_long\n -print-env\n -client\n -temp_file\n -readfile\n -app.\n"

arglist_out:  $(C2_O)arglist.o
	@g++ -o $(C2_B)arglist_out $(C2_O)arglist.o

getopt_out:  $(C2_O)getopt_long.o
	@g++ -o $(C2_B)getopt_out $(C2_O)getopt_long.o

print_out:  $(C2_O)print-env.o
	@g++ -o $(C2_B)print_out $(C2_O)print-env.o

app_out: $(C2_O)app.o
	@gcc -o $(C2_B)app_out $(C2_O)app.o

client_out: $(C2_O)client.o
	@gcc -o $(C2_B)client_out $(C2_O)client.o

tifftest_out: $(C2_O)tifftest.o
	@gcc -o $(C2_B)tifftest_out $(C2_S)2.9/tifftest.c -ltiff

readfile_out: $(C2_O)readfile.o
	@gcc -o $(C2_B)readfile_out $(C2_O)readfile.o

temp_file_out: $(C2_O)temp_file.o
	@gcc -o $(C2_B)temp_file_out $(C2_O)temp_file.o


$(C2_O)arglist.o: $(C2_S)2.1/arglist.c
	@g++ -c $(C2_S)2.1/arglist.c -o $(C2_O)arglist.o

$(C2_O)getopt_long.o: $(C2_S)2.2/getopt_long.c
	@g++ -c $(C2_S)2.2/getopt_long.c -o $(C2_O)getopt_long.o

$(C2_O)print-env.o: $(C2_S)2.3/print-env.c
	@g++ -c $(C2_S)2.3/print-env.c -o $(C2_O)print-env.o

$(C2_O)client.o: $(C2_S)2.4/client.c
	@gcc -c $(C2_S)2.4/client.c -o $(C2_O)client.o

$(C2_O)temp_file.o: $(C2_S)2.5/temp_file.c
	@gcc -c $(C2_S)2.5/temp_file.c -o $(C2_O)temp_file.o

$(C2_O)readfile.o: $(C2_S)2.6/readfile.c
	@gcc -c $(C2_S)2.6/readfile.c -o $(C2_O)readfile.o

$(C2_O)app.o: $(C2_S)2.8/app.c
	@gcc -c $(C2_S)2.8/app.c -o $(C2_O)app.o

$(C2_O)tifftest.o: $(C2_S)2.9/tifftest.c
	@g++ -c $(C2_S)2.9/tifftest.c -o $(C2_O)tifftest.o

#Capitulo 3

capitulo3: carpeta3 print-pid_out system_out fork_out fork-exec_out sigusr1_out zombie_out sigchld_out
	@echo "Seleccionaste el Capitulo 3\n"
	@echo " - print-pid\n - system\n - fork\n - fork-exec\n - zombie\n - sigchld.\n"

print-pid_out:  $(C3_O)print-pid.o
	@g++ -o $(C3_B)print-pid_out $(C3_O)print-pid.o

system_out:  $(C3_O)system.o
	@g++ -o $(C3_B)system_out $(C3_O)system.o

fork_out:  $(C3_O)fork.o
	@g++ -o $(C3_B)fork_out $(C3_O)fork.o

fork-exec_out:  $(C3_O)fork-exec.o
	@g++ -o $(C3_B)fork-exec_out $(C3_O)fork-exec.o

sigusr1_out:  $(C3_O)sigusr1.o
	@g++ -o $(C3_B)sigusr1_out $(C3_O)sigusr1.o

zombie_out:  $(C3_O)zombie.o
	@g++ -o $(C3_B)zombie_out $(C3_O)zombie.o

sigchld_out:  $(C3_O)sigchld.o
	@g++ -o $(C3_B)sigchld_out $(C3_O)sigchld.o


$(C3_O)arglist.o: $(C3_S)2.1/arglist.c
	@g++ -c $(C3_S)2.1/arglist.c -o $(C3_O)arglist.o

$(C3_O)print-pid.o: $(C3_S)3.1/print-pid.c
	@g++ -c $(C3_S)3.1/print-pid.c -o $(C3_O)print-pid.o

$(C3_O)system.o: $(C3_S)3.2/system.c
	@g++ -c $(C3_S)3.2/system.c -o $(C3_O)system.o

$(C3_O)fork.o: $(C3_S)3.3/fork.c
	@g++ -c $(C3_S)3.3/fork.c -o $(C3_O)fork.o

$(C3_O)fork-exec.o: $(C3_S)3.4/fork-exec.c
	@g++ -c $(C3_S)3.4/fork-exec.c -o $(C3_O)fork-exec.o -w

$(C3_O)sigusr1.o: $(C3_S)3.5/sigusr1.c
	@g++ -c $(C3_S)3.5/sigusr1.c -o $(C3_O)sigusr1.o

$(C3_O)zombie.o: $(C3_S)3.6/zombie.c
	@g++ -c $(C3_S)3.6/zombie.c -o $(C3_O)zombie.o

$(C3_O)sigchld.o: $(C3_S)3.7/sigchld.c
	@g++ -c $(C3_S)3.7/sigchld.c -o $(C3_O)sigchld.o


#Compilado del capitulo 4

capitulo4: carpeta4 thread-create thread-create2 thread-create3 primes detached critical-section \
	tsd cleanup cxx-exit job-queue1 job-queue2 job-queue3 spin-condvar condvar thread-pid
	@echo "Seleccionaste el Capitulo 4\n"
	@echo " - thread-create\n - thread-create2\n - thread-create3\n - primes\n - detached\n - critical-section\n"
	@echo " - tsd\n - cleanup\n - cxx-exit\n - job-queue1\n - job-queue2\n - job-queue3\n - spin-condvar\n - condvar\n - thread-pid\n"

thread-create: $(C4_O)thread-create.o
	@gcc -o $(C4_B)thread-create $(C4_O)thread-create.o -lpthread

thread-create2: $(C4_O)thread-create2.o
	@gcc -o $(C4_B)thread-create2 $(C4_O)thread-create2.o -lpthread

thread-create3: $(C4_O)thread-create3.o
	@gcc -o $(C4_B)thread-create3 $(C4_O)thread-create3.o -lpthread

primes: $(C4_O)primes.o
	@gcc -o $(C4_B)primes $(C4_O)primes.o -lpthread

detached: $(C4_O)detached.o
	@gcc -o $(C4_B)detached $(C4_O)detached.o -lpthread

critical-section: $(C4_O)critical-section.o
	@gcc -o $(C4_B)critical-section $(C4_O)critical-section.o -lpthread

tsd: $(C4_O)tsd.o
	@gcc -o $(C4_B)tsd $(C4_O)tsd.o -lpthread

cleanup: $(C4_O)cleanup.o
	@gcc -o $(C4_B)cleanup $(C4_O)cleanup.o -lpthread

cxx-exit: $(C4_O)cxx-exit.o
	@g++ -o $(C4_B)cxx-exit $(C4_O)cxx-exit.o -lpthread

job-queue1: $(C4_O)job-queue1.o
	@gcc -o $(C4_B)job-queue1 $(C4_O)job-queue1.o -lpthread

job-queue2: $(C4_O)job-queue2.o
	@gcc -o $(C4_B)job-queue2 $(C4_O)job-queue2.o -lpthread

job-queue3: $(C4_O)job-queue3.o
	@gcc -o $(C4_B)job-queue3 $(C4_O)job-queue3.o -lpthread

spin-condvar: $(C4_O)spin-condvar.o
	@gcc -o $(C4_B)spin-condvar $(C4_O)spin-condvar.o -lpthread

condvar: $(C4_O)condvar.o
	@gcc -o $(C4_B)condvar $(C4_O)condvar.o -lpthread

thread-pid: $(C4_O)thread-pid.o
	@gcc -o $(C4_B)thread-pid $(C4_O)thread-pid.o -lpthread

$(C4_O)thread-create.o: $(C4_S)4.1/thread-create.c
	@gcc -c $(C4_S)4.1/thread-create.c -o $(C4_O)thread-create.o

$(C4_O)thread-create2.o: $(C4_S)4.2/thread-create2.c
	@gcc -c $(C4_S)4.2/thread-create2.c -o $(C4_O)thread-create2.o

$(C4_O)thread-create3.o: $(C4_S)4.3/thread-create3.c
	@gcc -c $(C4_S)4.3/thread-create3.c -o $(C4_O)thread-create3.o

$(C4_O)primes.o: $(C4_S)4.4/primes.c
	@gcc -c $(C4_S)4.4/primes.c -o $(C4_O)primes.o -w

$(C4_O)detached.o: $(C4_S)4.5/detached.c
	@gcc -c $(C4_S)4.5/detached.c -o $(C4_O)detached.o

$(C4_O)critical-section.o: $(C4_S)4.6/critical-section.c
	@gcc -c $(C4_S)4.6/critical-section.c -o $(C4_O)critical-section.o

$(C4_O)tsd.o: $(C4_S)4.7/tsd.c
	@gcc -c $(C4_S)4.7/tsd.c -o $(C4_O)tsd.o

$(C4_O)cleanup.o: $(C4_S)4.8/cleanup.c
	@gcc -c $(C4_S)4.8/cleanup.c -o $(C4_O)cleanup.o

$(C4_O)cxx-exit.o: $(C4_S)4.9/cxx-exit.cpp
	@g++ -c $(C4_S)4.9/cxx-exit.cpp -o $(C4_O)cxx-exit.o

$(C4_O)job-queue1.o: $(C4_S)4.10/job-queue1.c
	@gcc -c $(C4_S)4.10/job-queue1.c -o $(C4_O)job-queue1.o

$(C4_O)job-queue2.o: $(C4_S)4.11/job-queue2.c
	@gcc -c $(C4_S)4.11/job-queue2.c -o $(C4_O)job-queue2.o

$(C4_O)job-queue3.o: $(C4_S)4.12/job-queue3.c
	@gcc -c $(C4_S)4.12/job-queue3.c -o $(C4_O)job-queue3.o

$(C4_O)spin-condvar.o: $(C4_S)4.13/spin-condvar.c
	@gcc -c $(C4_S)4.13/spin-condvar.c -o $(C4_O)spin-condvar.o

$(C4_O)condvar.o: $(C4_S)4.14/condvar.c
	@gcc -c $(C4_S)4.14/condvar.c -o $(C4_O)condvar.o

$(C4_O)thread-pid.o: $(C4_S)4.15/thread-pid.c
	@gcc -c $(C4_S)4.15/thread-pid.c -o $(C4_O)thread-pid.o

#Compilado del capitulo 5

capitulo5: carpeta5 shm semIm mmap-write mmap-read pipe dup2 popen socket-server socket-client socket-inet
	@echo "\nSeleccionaste el capitulo 5\n"
	@echo " - shm\n - semIm\n - mmap-write\n - mmap-read\n - pipe\n - dup2\n - popen\n - socket-server\n - socket-client\n - socket-inet"
	@echo "Ejecute mmap-write en bin con : ./mmap-write <nombre de archivo>\n"
	@echo "Ejecute mmap-read en bin con : ./mmap-write <nombre del archivo seleccionado en mmap-write>\n"
	@echo "Ejecute socket-server en bin con : ./socket-server <nombre del socket>\n"
	@echo "Ejecute socket-client en bin con : ./socket-server <nombre del socket (usado en socket-server)> [mensaje]\n"
	@echo "Ejecute socket-inet en bin con : ./socket-inet <url>\n"

shm: $(C5_S)5.1/shm.c
	@gcc $(C5_S)5.1/shm.c -o $(C5_B)shm


semIm: $(C5_S)5.4/semaphoreImplementation.c $(C5_O)sem_all_deall.o $(C5_O)sem_init.o  $(C5_O)sem_pv.o
	@gcc  $(C5_S)5.4/semaphoreImplementation.c $(C5_O)sem_all_deall.o $(C5_O)sem_init.o  $(C5_O)sem_pv.o -o $(C5_B)semIm -pthread

$(C5_O)sem_all_deall.o: $(C5_S)5.2/sem_all_deall.c
	@gcc -c $(C5_S)5.2/sem_all_deall.c -o $(C5_O)sem_all_deall.o -I $(C5_S)5.4/

$(C5_O)sem_init.o: $(C5_S)5.3/sem_init.c
	@gcc -c $(C5_S)5.3/sem_init.c -o $(C5_O)sem_init.o -I $(C5_S)5.4/

$(C5_O)sem_pv.o: $(C5_S)5.4/sem_pv.c
	@gcc -c $(C5_S)5.4/sem_pv.c -o $(C5_O)sem_pv.o -I $(C5_S)5.4/
mmap-write: $(C5_S)5.5/mmap-write.c
	@gcc $(C5_S)5.5/mmap-write.c -o $(C5_B)mmap-write

mmap-read: $(C5_S)5.6/mmap-read.c
	@gcc $(C5_S)5.6/mmap-read.c -o $(C5_B)mmap-read

pipe: $(C5_S)5.7/pipe.c
	@gcc $(C5_S)5.7/pipe.c -o $(C5_B)pipe

dup2:	$(C5_S)5.8/dup2.c
	@gcc $(C5_S)5.8/dup2.c -o $(C5_B)dup2

popen: $(C5_S)5.9/popen.c
	@gcc $(C5_S)5.9/popen.c -o $(C5_B)popen

socket-server: $(C5_S)5.10/socket-server.c
	@gcc $(C5_S)5.10/socket-server.c -o $(C5_B)socket-server

socket-client: $(C5_S)5.11/socket-client.c
	@gcc $(C5_S)5.11/socket-client.c -o $(C5_B)socket-client

socket-inet: $(C5_S)5.12/socket-inet.c
	@gcc $(C5_S)5.12/socket-inet.c -o $(C5_B)socket-inet

#Crear y eliminar los directorios
carpetas:
	@mkdir -p $(folder)

carpeta1:
	@mkdir -p $(folder1)

carpeta2:
	@mkdir -p $(folder2)

carpeta3:
	@mkdir -p $(folder3)

carpeta4:
	@mkdir -p $(folder4)

carpeta5:
	@mkdir -p $(folder5)

clean:
	@rm -r $(BINDIR) $(OBJECTDIR)
	@echo "Se han eliminado correctamente los directorios /src /obj"

#Listings del libro

#Capitulo 1

listing1: carpeta1 capitulo1

listing-1.1: listing1
	@echo "Compilado de listing 1, 2 y 3 (Hay dependencias)."

listing-1.2: listing1
	@echo "Compilado de listing 1, 2 y 3 (Hay dependencias)."

listing-1.3: listing1
	@echo "Compilado de listing 1, 2 y 3 (Hay dependencias)."

#Capitulo 2

listing2: carpeta2

listing-2.1: listing2 $(C2_O)arglist.o arglist_out
	@echo "Compilado del listing 2.1."

listing-2.2: listing2 $(C2_O)getopt_long.o getopt_out
	@echo "Compilado del listing 2.2."

listing-2.3: listing2 $(C2_O)print-env.o print_out
	@echo "Compilado del listing 2.3."

listing-2.4: listing2 $(C2_O)client.o client_out
	@echo "Compilado del listing 2.4."

listing-2.5: listing2 $(C2_O)temp_file.o temp_file_out
	@echo "Compilado del listing 2.5."

listing-2.6: listing2 $(C2_O)readfile.o readfile_out
	@echo "Compilado del listing 2.6."

listing-2.8: listing2 $(C2_O)app.o app_out
	@echo "Compilado del listing 2.8."

listing-2.9: listing2 $(C2_O)tifftest.o tifftest_out
	@echo "Compilado del listing 2.9."


#Capitulo 3

listing3: carpeta3

listing-3.1: listing3 $(C3_O)print-pid.o print-pid_out
	@echo "Compilado del listing 3.1."

listing-3.2: listing3 $(C3_O)system.o system_out
	@echo "Compilado del listing 3.2."

listing-3.3: listing3 $(C3_O)fork.o fork_out
	@echo "Compilado del listing 3.3."

listing-3.4: listing3 $(C3_O)fork-exec.o fork-exec_out
	@echo "Compilado del listing 3.4."

listing-3.5: listing3 $(C3_O)sigusr1.o sigusr1_out
	@echo "Compilado del listing 3.5."

listing-3.6: listing3 $(C3_O)zombie.o zombie_out
	@echo "Compilado del listing 3.6."

listing-3.7: listing3 $(C3_O)sigchld.o sigchld_out
	@echo "Compilado del listing 3.7."

#Capitulo 4

listing4: carpeta4

listing-4.1: listing4 thread-create
	@echo "Compilado del listing 4.1"

listing-4.2: listing4 thread-create2
	@echo "Compilado del listing 4.2"

listing-4.3: listing4 thread-create3
	@echo "Compilado del listing 4.3"

listing-4.4: listing4 primes
	@echo "Compilado del listing 4.4"

listing-4.5: listing4 detached
	@echo "Compilado del listing 4.5"

listing-4.6: listing4 critical-section
	@echo "Compilado del listing 4.6"

listing-4.7: listing4 tsd
	@echo "Compilado del listing 4.7"

listing-4.8: listing4 cleanup
	@echo "Compilado del listing 4.8"

listing-4.9: listing4 cxx-exit
	@echo "Compilado del listing 4.9"

listing-4.10: listing4 job-queue1
	@echo "Compilado del listing 4.10"

listing-4.11: listing4 job-queue2
	@echo "Compilado del listing 4.11"

listing-4.12: listing4 job-queue3
	@echo "Compilado del listing 4.12"

listing-4.13: listing4 spin-condvar
	@echo "Compilado del listing 4.13"

listing-4.14: listing4 condvar
	@echo "Compilado del listing 4.14"

listing-4.15: listing4 thread-pid
	@echo "Compilado del listing 4.15"

#Capitulo 5

listing5: carpeta5

listing-5.1: listing5 shm
	@echo "Compilado del listing 5.1."

listing234: listing5 semIm

listing-5.2: listing234
	@echo "Compilado de los listing 5.2 5.3 y 5.4 (Hay dependencias)"

listing-5.3: listing234
	@echo "Compilado de los listing 5.2 5.3 y 5.4 (Hay dependencias)"

listing-5.4: listing234
	@echo "Compilado de los listing 5.2 5.3 y 5.4 (Hay dependencias)"

listing-5.5: listing5 mmap-write
	@echo "Compilado del listing 5.5."

listing-5.6: listing5 mmap-read
	@echo "Compilado del listing 5.6."

listing-5.7: listing5 pipe
	@echo "Compilado del listing 5.7."

listing-5.8: listing5 dup2
	@echo "Compilado del listing 5.8."

listing-5.9: listing5 popen
	@echo "Compilado del listing 5.9."

listing-5.10: listing5 socket-server
	@echo "Compilado del listing 5.10."

listing-5.11: listing5 socket-client
	@echo "Compilado del listing 5.11."

listing-5.12: listing5 socket-inet
	@echo "Compilado del listing 5.12."
