CC = gcc
TARGET = game.exe
CFLAGS = -Wall -Wextra -std=c99 -I./include
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm -lm  -lraylib lib/libraylib.a
src = main.c map.c player.c raycaster.c
all:
	$(CC) $(src) -o $(TARGET) $(CFLAGS) $(LDFLAGS)
