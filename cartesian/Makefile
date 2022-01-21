OUTPUT=out



all: descartes.o
	gcc descartes.o main.c -o $(OUTPUT) -lm -Wall

descartes.o: descartes.h
	gcc -c descartes.c -lm -Wall

run:
	./$(OUTPUT)
	
clean:
	rm -rf *.o out