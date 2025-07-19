#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

int menu (void);
int main (void){
   int t = menu();
    if(t){
        printf("Funcionoooooo\n");
    }
    return 0;
}


int menu (void){
    initscr(); //initilize ncruses
    noecho(); //used so that the characters that are input are no displayed on screen
    curs_set(0);
    char opt=0;//creates variable opt
    int ymax, xmax; //creates two variables one to store the y-coordinate and the other to store the x-coordinate
    getmaxyx(stdscr, ymax, xmax);
    WINDOW *win = newwin(ymax/2, xmax/2, ymax/4, xmax/4);
    box(win, 0, 0);
    mvwprintw(win, 0, xmax/5.5, "**FLAPPY BIRD**"); //Menu display
    mvwprintw(win, 1, 5, "Type option number you wish to select");
    mvwprintw(win, 3, xmax/5, "1-Start");
    mvwprintw(win, 5, xmax/5, "2-Quit");
    mvwprintw(win, 7, xmax/5, " ______");
    mvwprintw(win, 8, xmax/5, "|    > |");
    mvwprintw(win, 9, xmax/5, "| ( )  >");
    mvwprintw(win, 10, xmax/5, "|______|");

    opt = wgetch(win); //
    endwin(); //ends ncurses
    if(opt=='1'){
        return 1;
    }
    else{
        return 0;
    }
}