#include <ncurses.h>
#include "bird.h"
#include "bird_graphics.h"


void init_bird(bird_t * bird){
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x); // We get the max size of the screen
    bird->bird_x = max_x / 3; // The burd will be at 1/3 of the screen
    bird->bird_y = max_y / 2; // The bird will be at the middle of the screen
    bird->velocity = 0.0f; // Initial velocity
    bird->acceleration = GRAVITY; // Gravity acceleration   

    bird->shape.fwings = "  \\\\"; // String of the flying wings
    bird->shape.dwings = "  //"; // String of the descending
    bird->shape.body = "////(0)>"; // String of the body   

}
void draw_fbird(bird_t * bird){
    int max_y = getmaxy(stdscr); //gets the max Y size of the screen
    // Limit the position of the bird within the screen
    if(bird->bird_y >= max_y) bird->bird_y = max_y - 1; 
    if(bird->bird_y < 0) bird->bird_y = 0;

    mvprintw(bird->bird_y, bird->bird_x, "%s", bird->shape.fwings); // It draws first the wings
    mvprintw(bird->bird_y + 1, bird->bird_x, "%s", bird->shape.body);// then it draws the body
    refresh();
}
void draw_dbird(bird_t * bird){
    int max_y = getmaxy(stdscr); // gets the max Y size of the screen
    // Limit the position of the bird within the screen
    if(bird->bird_y >= max_y) bird->bird_y = max_y - 1;
    if(bird->bird_y < 1) bird->bird_y = 1;

    mvprintw(bird->bird_y, bird->bird_x, "%s", bird->shape.body); //It draws first the body
    mvprintw(bird->bird_y +1, bird->bird_x, "%s", bird->shape.dwings);// Then it draws the wings
    refresh();
}