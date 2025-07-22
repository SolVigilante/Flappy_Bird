#include <ncurses.h>
#include "screen.h"

void init_screen(void){
    initscr(); // Initializes the ncurses screen
    curs_set(0); // Hides the cursor
    keypad(stdscr, TRUE);//enables the keypad input
    noecho(); //deletes thte input character
    cbreak(); // Disables line buffering, so input is available immediately
    timeout(100); // Waits 100ms for a key, then returns ERR 
}