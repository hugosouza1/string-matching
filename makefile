run:
	./tp3.exe entrada.txt

build: main.o fila.o leitura.o
	gcc main.o fila.o leitura.o -o tp3.exe

main.o: main.c fila.h
	gcc -c main.c -o main.o

fila.o: fila.c fila.h
	gcc -c fila.c -o fila.o

leitura: leitura.c leitura.h fila.o
	gcc -c leitura.c -o leitura.o

clean:
	rm -f *.o *.exe