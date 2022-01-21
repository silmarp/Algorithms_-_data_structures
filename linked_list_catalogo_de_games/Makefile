OUTPUT=out
MAIN=src/main.c


all: clean games.o catalogo.o
	gcc games.o catalogo.o $(MAIN) -o $(OUTPUT) -Wall

games.o:
	gcc -c src/games.c -Wall

catalogo.o:
	gcc -c src/catalogo.c -Wall

run:
	./$(OUTPUT)

clean:
	rm -rf *.o out
