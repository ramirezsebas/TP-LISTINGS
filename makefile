# Directorio Principal
ROOT := ./

# Directorio src donde estan los archivos .c.
DIRECTORIO_SRC   := $(ROOT)src/

# Directorio obj donde estan los archivos .o. (Object Files)
DIRECTORIO_OBJ   := $(ROOT)obj/

# Directorio bin donde estan los archivos compilados.
DIRECTORIO_BIN   := $(ROOT)bin/

# Directorio src del Capitulo 1
DIRECTORIO_SRC_CAPITULO_1 := $(DIRECTORIO_SRC)capitulo_1/

# Directorio src del Capitulo 2
DIRECTORIO_SRC_CAPITULO_2 := $(DIRECTORIO_SRC)capitulo_2/

# Directorio src del Capitulo 3
DIRECTORIO_SRC_CAPITULO_3 := $(DIRECTORIO_SRC)capitulo_3/

# Directorio src del Capitulo 4
DIRECTORIO_SRC_CAPITULO_4 := $(DIRECTORIO_SRC)capitulo_4/

# Directorio src del Capitulo 5
DIRECTORIO_SRC_CAPITULO_5 := $(DIRECTORIO_SRC)capitulo_5/

# Directorio obj del Capitulo 1
DIRECTORIO_OBJ_CAPITULO_1 := $(DIRECTORIO_OBJ)capitulo_1/

# Directorio obj del Capitulo 2
DIRECTORIO_OBJ_CAPITULO_2 := $(DIRECTORIO_OBJ)capitulo_2/

# Directorio obj del Capitulo 3
DIRECTORIO_OBJ_CAPITULO_3 := $(DIRECTORIO_OBJ)capitulo_3/

# Directorio obj del Capitulo 4
DIRECTORIO_OBJ_CAPITULO_4 := $(DIRECTORIO_OBJ)capitulo_4/

# Directorio obj del Capitulo 5
DIRECTORIO_OBJ_CAPITULO_5 := $(DIRECTORIO_OBJ)capitulo_5/



# Capitulo 1
HEADER_RECIPROCAL := $(DIRECTORIO_SRC_CAPITULO_1)/1.3/reciprocal.hpp 

all: $(HEADER_RECIPROCAL)
	@make listing-1.1
	@make listing-1.2
	@echo "[*] Compilando todos los capitulos en el ./obj/"

listing-1.1: $(HEADER_RECIPROCAL)
	@echo "Creando el Object File main.o"
	@mkdir -p obj && mkdir -p obj/capitulo_1
	@gcc -c $(DIRECTORIO_SRC_CAPITULO_1)1.1/main.c -o $(DIRECTORIO_OBJ_CAPITULO_1)main.o

listing-1.2: $(HEADER_RECIPROCAL)
	@echo "Creando el Object File reciprocal.o"
	@mkdir -p obj && mkdir -p obj/capitulo_1
	@g++ -c $(DIRECTORIO_SRC_CAPITULO_1)1.2/reciprocal.cpp -o $(DIRECTORIO_OBJ_CAPITULO_1)reciprocal.o

clean:
	@mkdir -p obj && mkdir -p obj/capitulo_1
	@rm -rf ./obj/*
	@mkdir ./obj/capitulo_1
	@mkdir ./obj/capitulo_2
	@mkdir ./obj/capitulo_3
	@mkdir ./obj/capitulo_4
	@mkdir ./obj/capitulo_5
	@echo "[*] Eliminando todas las compilaciones del directorio ./obj/"
	@echo "[*] Creando las Carpetas correspondientes a cada Capitulo en el directorio ./obj/."
