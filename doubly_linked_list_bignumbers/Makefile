OUTPUT=out
MAIN=big.c


all: clean list.o
	gcc list.o $(MAIN) -o $(OUTPUT) -Wall

list.o:
	gcc -c list.c -Wall

run:
	./$(OUTPUT)

clean:
	rm -rf *.o out
