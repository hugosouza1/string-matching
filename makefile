OBJ_DIR = ./objetos
SRC_DIR = ./estrutura-de-dados

estrutura-de-dados = $(OBJ_DIR)/fila.o

run: build
	./tp3.exe entrada.txt

leak:
	valgrind --leak-check=full --show-leak-kinds=all ./tp3.exe entrada.txt

build: $(OBJ_DIR)/main.o $(OBJ_DIR)/leitura.o $(OBJ_DIR)/forcaBruta.o $(OBJ_DIR)/fila.o $(estrutura-de-dados)
	gcc $(OBJ_DIR)/main.o $(OBJ_DIR)/leitura.o $(OBJ_DIR)/forcaBruta.o $(OBJ_DIR)/fila.o -o ./tp3.exe -lm

$(OBJ_DIR)/main.o: ./main.c | $(OBJ_DIR)
	gcc -c ./main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/fila.o: $(SRC_DIR)/fila.c $(SRC_DIR)/fila.h | $(OBJ_DIR)
	gcc -c $(SRC_DIR)/fila.c -o $(OBJ_DIR)/fila.o

$(OBJ_DIR)/leitura.o: ./leitura.c ./leitura.h | $(OBJ_DIR)
	gcc -c ./leitura.c -o $(OBJ_DIR)/leitura.o

$(OBJ_DIR)/forcaBruta.o: ./forcaBruta.c ./forcaBruta.h | $(OBJ_DIR)
	gcc -c ./forcaBruta.c -o $(OBJ_DIR)/forcaBruta.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f tp3.exe