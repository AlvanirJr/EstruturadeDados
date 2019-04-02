all: heap.out


heap.out: main.o heap.o
	gcc heap.o main.o -o heap.out


heap.o: heap.c
	gcc -c heap.c -o heap.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f *.out *.o *.*~ *~