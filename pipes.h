#ifndef PIPES_H
#define PIPES_H
#define WIDTH 7 //the pipes always have the same width
#define GAP 6 //size of gap
typedef struct{
    float position; //position of the pipes
    int gap_height;  //height of gap
}pipe_t;
#endif