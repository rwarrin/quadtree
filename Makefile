CC = clang
CFLAGS = -std=c11 -g -ggdb -Wall -Werror -Wextra -pedantic -O0 -I$(INC_DIR)

BIN_DIR = ./bin/
OBJ_DIR = ./obj/
SRC_DIR = ./src/
INC_DIR = ./include/
LIB_DIR = ./lib/

all: node.o quadtree.o main.o app

app:
	$(CC) $(CFLAGS) $(OBJ_DIR)*.o -o $(BIN_DIR)$@

main.o: $(SRC_DIR)main.c
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@

node.o: $(SRC_DIR)node.c $(INC_DIR)node.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@

quadtree.o: $(SRC_DIR)quadtree.c $(INC_DIR)quadtree.h
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@

clean:
	rm -rf bin/app *.exe *.o *.out

