main=main.c
output=out

all: tree.o item.o
	gcc item.o tree.o $(main) -o $(output) 

item.o:
	gcc -c item.c 

tree.o:
	gcc -c tree.c

clean:
	rm *.o $(output)

run:
	./$(output)

test:
	./$(output) < 1.in
