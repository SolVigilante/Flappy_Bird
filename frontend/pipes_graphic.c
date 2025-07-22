
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipes_graphic.h"
#include "../pipe.h"

// Draw a pipe on the screen at its current position
void draw_pipes(pipe_t *pipe){
    attron(COLOR_PAIR(1)); // Enable color pair 1 (green on blue)
    for(int y_coordinate = 0; y_coordinate < LINES; y_coordinate++){ // Draw the pipe only outside the gap (above and below)
        if(y_coordinate < pipe->gap_height || y_coordinate > pipe->gap_height + GAP){
            for(int width = 0; width <= WIDTH; width++){
                mvaddch(y_coordinate, pipe->position + width, '*'); // Draw pipe character
            }
        }
    }
    attroff(COLOR_PAIR(1)); // Disable color pair
}

// Erase the pipe from the screen by replacing it with spaces
void erase_pipes(pipe_t *pipe){
    for(int y = 0; y < LINES; y++){
        for(int w = 0; w <= WIDTH; w++){
            mvaddch(y, pipe->position + w, ' '); // Erase with space character
        }
    }
}