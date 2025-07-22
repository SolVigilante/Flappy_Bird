#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "bird.h"
#include "frontend/bird_graphics.h"
#include "backend/flying_logic.h"
#include "backend/menu.h"
#include "backend/screen.h"
#include "pipe.h"



int main(){
    static char c; // Variable to store the input character
    static int t;
    long long last_gravity_time = current_time_ms();//stores the initial time in milliseconds
    bird_t bird;
    init_bird(&bird); // Initializes the bird
    pipe_t *pipe = malloc(sizeof(pipe_t)); // Allocate memory for a pipe and initialize its position and gap
    pipe->position = COLS - WIDTH; // Start pipe at far right of screen
    pipe->gap_height = rand() % (LINES - GAP - 2) + 1; // Random gap position

    while((t = menu())!=1 && t!=0); //loop until a valid option is selected
    if(t==1){
        init_screen(); // Initializes the screen
        while((c = getch()) != 'q'){
           last_gravity_time = game_start(c, last_gravity_time, &bird); // Starts the game loop
           pipes(pipe); // Moves the pipes
        }
    }
    free(pipe); // memory cleanup
    endwin(); // Ends the ncurses mode
    return 0;
}
