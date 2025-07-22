#include <ncurses.h>
#include "screen.h"

void init_screen(void){
    initscr(); // Initializes the ncurses screen
    curs_set(0); // Hides the cursor
    start_color(); // Enable color functionality
    init_pair(1, COLOR_GREEN, COLOR_BLUE); // Define color pair 1
    keypad(stdscr, TRUE);//enables the keypad input
    noecho(); //deletes thte input character
    cbreak(); // Disables line buffering, so input is available immediately
    timeout(100); // Waits 100ms for a key, then returns ERR 
}