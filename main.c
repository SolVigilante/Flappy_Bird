#include <ncurses.h>
#include "bird.h"
#include "bird_graphics.h"
#include "flying_logic.h"
#include "menu.h"
#include "screen.h"
#include "pipes.h"


int main(){
    static char c; // Variable to store the input character
    static int t;
    long long last_gravity_time = current_time_ms();//stores the initial time in milliseconds
    bird_t bird;
    init_bird(&bird); // Initializes the bird

    while((t = menu())!=1 && t!=0); //loop until a valid option is selected
    if(t==1){
        init_screen(); // Initializes the screen
        while((c = getch()) != 'q'){
           last_gravity_time = game_start(c, last_gravity_time, &bird); // Starts the game loop
        }
    }
    endwin(); // Ends the ncurses mode
    return 0;
}
