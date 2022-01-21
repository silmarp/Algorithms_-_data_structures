all: matrix.o
	gcc matrix.o main.c -o out

matrix.0:
	gcc -c matrix.c

clean:
	rm out *.o

run:
	./out

test: clean all
	./out < 1.in
