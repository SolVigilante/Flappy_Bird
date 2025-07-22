# Makefile for Flappy Bird project
CC := gcc
CFLAGS := -c -Wall

programa: bird_graphics.o main.o flying_logic.o menu.o screen.o
	${CC} bird_graphics.o main.o flying_logic.o menu.o screen.o -o programa -lncurses

bird_graphics.o: bird_graphics.c bird_graphics.h bird.h
	${CC} ${CFLAGS} bird_graphics.c 

main.o: main.c bird_graphics.h bird.h flying_logic.h
	${CC} ${CFLAGS} main.c 
flying_logic.o: flying_logic.c flying_logic.h bird_graphics.h bird.h
	${CC} ${CFLAGS} flying_logic.c
menu.o: menu.c menu.h
	${CC} ${CFLAGS} menu.c
screen.o: screen.c screen.h
	${CC} ${CFLAGS} screen.c
	
clean:
	rm *.o programa

run: programa
	./programa
