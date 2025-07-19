#include <ncurses.h>
#include "bird.h"
#include "bird_graphics.h"
#include "flying_logic.h"

static void flying_start(void);
static void init_screen(void){
    initscr(); // Initializes the ncurses screen
    curs_set(0); // Hides the cursor
    keypad(stdscr, TRUE);//enables the keypad input
    noecho(); //deletes thte input character
    cbreak(); // Disables line buffering, so input is available immediately
    timeout(100); // Waits 100ms for a key, then returns ERR 
    flying_start(); // Starts the game loop
}
static void flying_start(void){
    bird_t bird;
    init_bird(&bird); // Initializes the bird
    static char c;   
    while((c = getch()) != 'q'){ //q is the scape key
        clear();
        if( (c== ' ') && (bird.velocity > GRAVITY/10.0f)){ //It enables the flight when space key is pressed and the bird is falling
            bird.velocity = -GRAVITY/10.0f;// It sets the velocity o a negative value
            bird.acceleration = 0.0f; // It sets the acceleration to 0, so it doesn't fall immediately
        }else{
            bird.acceleration += GRAVITY*0.1f; //It adds a portion of the gravitty tto the acceleration everio 0.1 seconds 
        }
        if(bird.acceleration > GRAVITY){
            bird.acceleration = GRAVITY; // Limit the acceleration to the gravity
        }
        bird.velocity += bird.acceleration*0.1f; //Velocity in functtion of acceleration
        bird.bird_y += bird.velocity * 0.1f; //position in function of velocity

        if(bird.velocity < 0.0f){
            draw_fbird(&bird); // If the bird is flying, we draw the flying wings
        }else{
            draw_dbird(&bird); // If the bird is descending, we draw the descending wings
        }
    }
    endwin();
}

void game_start(void){ 
    init_screen(); // Initializes the screen
}