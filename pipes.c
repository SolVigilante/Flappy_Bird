#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipes.h"

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
void erase_pipe(pipe_t *pipe){
    for(int y = 0; y < LINES; y++){
        for(int w = 0; w <= WIDTH; w++){
            mvaddch(y, pipe->position + w, ' '); // Erase with space character
        }
    }
}
// Main loop that moves pipes continuously from right to left
void move_pipes(void){
    initscr(); // Initialize ncurses screen
    noecho(); // Disable key echoing
    curs_set(FALSE); // Hide the cursor
    start_color(); // Enable color functionality
    init_pair(1, COLOR_GREEN, COLOR_BLUE); // Define color pair 1
    pipe_t *pipe = malloc(sizeof(pipe_t)); // Allocate memory for a pipe and initialize its position and gap
    pipe->position = COLS - WIDTH; // Start pipe at far right of screen
    pipe->gap_height = rand() % (LINES - GAP - 2) + 1; // Random gap position
    while(1){ //When we have the player lives we need to change it so that its not an infinite loop
        erase_pipe(pipe); // Remove the previous pipe position
        pipe->position -= 1; // Move pipe one column to the left
        if(pipe->position < -WIDTH){ // If the pipe moved completely off screen, reset it to the right side
            pipe->position = COLS - WIDTH;
            pipe->gap_height = rand() % (LINES - GAP - 2) + 1; // New random gap
        }
        draw_pipes(pipe); // Draw the pipe in the new position
        refresh(); // Update the screen
        usleep(10000);// Small delay for smooth animation (10ms)
    }
    free(pipe); // memory cleanup
    endwin();   //properly ends ncurses mode
}
