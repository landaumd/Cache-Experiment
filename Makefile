project: main.o memory.o
	gcc main.o memory.o -o project
main.o: main.c memory.h
	gcc -c main.c -Wall
memory.o: memory.c memory.h
	gcc -c -Wall memory.c
