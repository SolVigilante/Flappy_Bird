#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipes_movement.h"
#include "../pipe.h"
#include "frontend/pipes_graphic.h"

static void move_pipe (pipe_t *pipe);

// Main loop
void pipes(pipe_t *pipe) {
        erase_pipes(pipe); // Remove the previous pipe position
        move_pipe(pipe); //Moves pipe 
        draw_pipes(pipe); // Draw the pipe in the new position
        refresh(); // Update the screen
        usleep(10000);// Small delay for smooth animation (10ms)
}
//Moves pipe
static void move_pipe (pipe_t *pipe){
      pipe->position -= 1; // Move pipe one column to the left
        if(pipe->position < -WIDTH){ // If the pipe moved completely off screen, reset it to the right side
            pipe->position = COLS - WIDTH;
            pipe->gap_height = rand() % (LINES - GAP - 2) + 1; // New random gap
        }
}
