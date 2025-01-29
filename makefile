OBJ_DIR = ./objetos
SRC_DIR = ./estrutura-de-dados
metodo ?= 5

estrutura-de-dados = $(OBJ_DIR)/fila.o

run: build
	./tp3.exe entrada.txt $(metodo)

leak: build
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./tp3.exe entrada.txt $(metodo)

build: $(OBJ_DIR)/main.o $(OBJ_DIR)/leitura.o $(OBJ_DIR)/forcaBruta.o $(OBJ_DIR)/KMP.o $(OBJ_DIR)/fila.o $(OBJ_DIR)/tons.o $(OBJ_DIR)/BMH.o $(OBJ_DIR)/shiftAnd.o $(estrutura-de-dados)
	gcc $(OBJ_DIR)/main.o $(OBJ_DIR)/leitura.o $(OBJ_DIR)/forcaBruta.o $(OBJ_DIR)/KMP.o $(OBJ_DIR)/fila.o $(OBJ_DIR)/tons.o $(OBJ_DIR)/BMH.o $(OBJ_DIR)/shiftAnd.o -o ./tp3.exe -lm

$(OBJ_DIR)/main.o: ./main.c | $(OBJ_DIR)
	gcc -c ./main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/fila.o: $(SRC_DIR)/fila.c $(SRC_DIR)/fila.h | $(OBJ_DIR)
	gcc -c $(SRC_DIR)/fila.c -o $(OBJ_DIR)/fila.o

$(OBJ_DIR)/leitura.o: ./leitura.c ./leitura.h | $(OBJ_DIR)
	gcc -c ./leitura.c -o $(OBJ_DIR)/leitura.o

$(OBJ_DIR)/forcaBruta.o: ./forcaBruta.c ./forcaBruta.h | $(OBJ_DIR)
	gcc -c ./forcaBruta.c -o $(OBJ_DIR)/forcaBruta.o

$(OBJ_DIR)/KMP.o: ./KMP.c ./KMP.h | $(OBJ_DIR)
	gcc -c ./KMP.c -o $(OBJ_DIR)/KMP.o

$(OBJ_DIR)/BMH.o: ./BMH.c ./BMH.h | $(OBJ_DIR)
	gcc -c ./BMH.c -o $(OBJ_DIR)/BMH.o

$(OBJ_DIR)/shiftAnd.o: ./shiftAnd.c ./shiftAnd.h | $(OBJ_DIR)
	gcc -c ./shiftAnd.c -o $(OBJ_DIR)/shiftAnd.o

$(OBJ_DIR)/tons.o: ./tons.c ./tons.h | $(OBJ_DIR)
	gcc -c ./tons.c -o $(OBJ_DIR)/tons.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f tp3.exe