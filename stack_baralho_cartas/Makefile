MAIN=main.c
OUTPUT=out


all: clean pilha.o cartas.o
	gcc cartas.o pilha.o $(MAIN) -o $(OUTPUT) -Wall


pilha.o:
	gcc -c pilha.c -Wall

cartas.o:
	gcc -c cartas.c -Wall

clean:
	rm -rf *.o out

run:
	./$(OUTPUT)

valgrind:
	valgrind --leak-check=full ./$(OUTPUT) < teste.txt
