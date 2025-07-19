#include <ncurses.h>
#include "bird.h"
#include "bird_graphics.h"
#include "flying_logic.h"
#include "menu.h"


int main(){
    int t;
    while((t = menu())!=1 && t!=0); //loop until a valid option is selected
    if(t==1){
        game_start(); // Starts the game loop
    }
    return 0;
}
