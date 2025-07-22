# Makefile for Flappy Bird project (con -I. para includes desde subdirectorios)

CC := gcc
CFLAGS := -c -Wall -I.

programa: main.o flying_logic.o menu.o pipes_movement.o bird_graphics.o pipes_graphic.o screen.o
	${CC} $^ -o programa -lncurses

main.o: main.c backend/flying_logic.h backend/menu.h backend/pipes_movement.h frontend/bird_graphics.h frontend/pipes_graphic.h pipe.h bird.h
	${CC} ${CFLAGS} main.c

flying_logic.o: backend/flying_logic.c backend/flying_logic.h bird.h
	${CC} ${CFLAGS} backend/flying_logic.c

menu.o: backend/menu.c backend/menu.h
	${CC} ${CFLAGS} backend/menu.c

pipes_movement.o: backend/pipes_movement.c backend/pipes_movement.h
	${CC} ${CFLAGS} backend/pipes_movement.c

bird_graphics.o: frontend/bird_graphics.c frontend/bird_graphics.h bird.h
	${CC} ${CFLAGS} frontend/bird_graphics.c

pipes_graphic.o: frontend/pipes_graphic.c frontend/pipes_graphic.h
	${CC} ${CFLAGS} frontend/pipes_graphic.c
screen.o: backend/screen.c backend/screen.h
	${CC} ${CFLAGS} backend/screen.c

clean:
	rm -f *.o backend/*.o frontend/*.o programa

run: programa
	./programa

