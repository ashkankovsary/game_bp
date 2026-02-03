CC = gcc
CFLAGS = -Wall -Wextra -std=c99
INC = -I./include -I/usr/local/include
SRC = main.c map.c player.c raycaster.c

ifeq ($(OS),Windows_NT)
    OUT = game.exe
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
else
    OUT = game
    LIBS = $(shell pkg-config --cflags --libs raylib) -lm
endif

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(INC) $(LIBS)