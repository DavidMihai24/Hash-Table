CFLAGS=-std=c99
build:
	gcc -g -o tema1 *.c
run:
	./tema1
clean:
	rm tema1
valgrind:
	valgrind --leak-check=yes --vgdb=no --track-origins=yes ./tema1 input/in2.txt