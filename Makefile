CC = g++
CFLAGS=-std=c++17 -c

main: main.o
	${CC} main.o -o main

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

.PHONY: clean
clean:
	rm -f main *.o

.PHONY: run
run:
	./main
