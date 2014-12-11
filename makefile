# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -O2 -I./include
CC = g++
TARGET = ./bin/Metalex

all: ./bin/Metalex

./src/main.o: ./src/main.c
	$(CC) -o ./src/main.o -I./include -c ./src/main.c

./src/expr.o: ./src/expr.c
	$(CC) -o ./src/expr.o -I./include -c ./src/expr.c

./src/rexpr.o: ./src/rexpr.c
	$(CC) -o ./src/rexpr.o -I./include -c ./src/rexpr.c

./src/genc.o: ./src/genc.c
	$(CC) -o ./src/genc.o -I./include -c ./src/genc.c

./bin/Metalex: ./src/main.o ./src/genc.o ./src/expr.o ./src/rexpr.o
	$(CC) $(CFLAGS) -o $(TARGET) ./src/main.o ./src/genc.o ./src/expr.o ./src/rexpr.o

clean:
	rm $(TARGET)
	rm ./src/*.o

